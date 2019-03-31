#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

struct TimeSlot {
    enum class Weekday { SAT, SUN, MON, TUE, WED, THU, FRI };
    enum class Time {
        T071, T072, T081, T082, T091, T092, T101, T102, T111, T112, T121, T122, T131, T132,
        T141, T142, T151, T152, T161, T162, T171, T172, T181, T182, T191, T192, T201, T202
    };
    Weekday weekday;
    Time start_time, end_time;
};

const vector<TimeSlot::Weekday> weekdays = {
    TimeSlot::Weekday::SAT,
    TimeSlot::Weekday::SUN,
    TimeSlot::Weekday::MON,
    TimeSlot::Weekday::TUE,
    TimeSlot::Weekday::WED,
    TimeSlot::Weekday::THU,
    TimeSlot::Weekday::FRI
};

const vector<TimeSlot::Time> time_atoms = {
    TimeSlot::Time::T071,
    TimeSlot::Time::T072,
    TimeSlot::Time::T081,
    TimeSlot::Time::T082,
    TimeSlot::Time::T091,
    TimeSlot::Time::T092,
    TimeSlot::Time::T101,
    TimeSlot::Time::T102,
    TimeSlot::Time::T111,
    TimeSlot::Time::T112,
    TimeSlot::Time::T121,
    TimeSlot::Time::T122,
    TimeSlot::Time::T131,
    TimeSlot::Time::T132,
    TimeSlot::Time::T141,
    TimeSlot::Time::T142,
    TimeSlot::Time::T151,
    TimeSlot::Time::T152,
    TimeSlot::Time::T161,
    TimeSlot::Time::T162,
    TimeSlot::Time::T171,
    TimeSlot::Time::T172,
    TimeSlot::Time::T181,
    TimeSlot::Time::T182,
    TimeSlot::Time::T191,
    TimeSlot::Time::T192,
    TimeSlot::Time::T201,
    TimeSlot::Time::T202
};

typedef unsigned int CourseCode;
typedef unsigned short GroupCode;

struct Offering {
    CourseCode course_code;
    GroupCode group_code;
    vector<TimeSlot> time_slots;
};

typedef pair<TimeSlot, Offering> ProgrammeCell;
typedef vector<ProgrammeCell> ProgrammeRow;
typedef map<TimeSlot::Weekday, vector<ProgrammeRow>> Programme;
typedef map<TimeSlot::Weekday, map<TimeSlot::Time, size_t>> ProgrammeLimits;

map<string, TimeSlot::Weekday> get_weekday_dict() {
    static map<string, TimeSlot::Weekday> weekday_dict;
    if (!weekday_dict.size()) {
        weekday_dict["SAT"] = TimeSlot::Weekday::SAT;
        weekday_dict["SUN"] = TimeSlot::Weekday::SUN;
        weekday_dict["MON"] = TimeSlot::Weekday::MON;
        weekday_dict["TUE"] = TimeSlot::Weekday::TUE;
        weekday_dict["WED"] = TimeSlot::Weekday::WED;
        weekday_dict["THU"] = TimeSlot::Weekday::THU;
        weekday_dict["FRI"] = TimeSlot::Weekday::FRI;
    }
    return weekday_dict;
}

string to_string(TimeSlot::Weekday weekday) {
    static map<TimeSlot::Weekday, string> weekday_name_dict;
    if (!weekday_name_dict.size()) {
        weekday_name_dict[TimeSlot::Weekday::SAT] = "Saturday";
        weekday_name_dict[TimeSlot::Weekday::SUN] = "Sunday";
        weekday_name_dict[TimeSlot::Weekday::MON] = "Monday";
        weekday_name_dict[TimeSlot::Weekday::TUE] = "Tuesday";
        weekday_name_dict[TimeSlot::Weekday::WED] = "Wednesday";
        weekday_name_dict[TimeSlot::Weekday::THU] = "Thursday";
        weekday_name_dict[TimeSlot::Weekday::FRI] = "Friday";
    }
    return weekday_name_dict[weekday];
}

size_t to_numerical(TimeSlot::Time time) {
    return distance(time_atoms.begin(), find(time_atoms.begin(), time_atoms.end(), time));
}

string to_string(TimeSlot::Time time) {
    const int first_hour = 7;
    const string hour_min_delim = ":";
    string res = to_string(first_hour + to_numerical(time) / 2) + hour_min_delim + (to_numerical(time) % 2 ? "30" : "00");
    return res.size() < 5 ? "0" + res : res;
}

map<string, TimeSlot::Time> get_time_dict() {
    static map<string, TimeSlot::Time> time_dict;
    if (!time_dict.size()) {
        time_dict["07:00"] = TimeSlot::Time::T071;
        time_dict["07:30"] = TimeSlot::Time::T072;
        time_dict["08:00"] = TimeSlot::Time::T081;
        time_dict["08:30"] = TimeSlot::Time::T082;
        time_dict["09:00"] = TimeSlot::Time::T091;
        time_dict["09:30"] = TimeSlot::Time::T092;
        time_dict["10:00"] = TimeSlot::Time::T101;
        time_dict["10:30"] = TimeSlot::Time::T102;
        time_dict["11:00"] = TimeSlot::Time::T111;
        time_dict["11:30"] = TimeSlot::Time::T112;
        time_dict["12:00"] = TimeSlot::Time::T121;
        time_dict["12:30"] = TimeSlot::Time::T122;
        time_dict["13:00"] = TimeSlot::Time::T131;
        time_dict["13:30"] = TimeSlot::Time::T132;
        time_dict["14:00"] = TimeSlot::Time::T141;
        time_dict["14:30"] = TimeSlot::Time::T142;
        time_dict["15:00"] = TimeSlot::Time::T151;
        time_dict["15:30"] = TimeSlot::Time::T152;
        time_dict["16:00"] = TimeSlot::Time::T161;
        time_dict["16:30"] = TimeSlot::Time::T162;
        time_dict["17:00"] = TimeSlot::Time::T171;
        time_dict["17:30"] = TimeSlot::Time::T172;
        time_dict["18:00"] = TimeSlot::Time::T181;
        time_dict["18:30"] = TimeSlot::Time::T182;
        time_dict["19:00"] = TimeSlot::Time::T191;
        time_dict["19:30"] = TimeSlot::Time::T192;
        time_dict["20:00"] = TimeSlot::Time::T201;
        time_dict["20:30"] = TimeSlot::Time::T202;
    }
    return time_dict;
}

CourseCode to_course_code(const string str) {
    return atoi(str.c_str());
}

GroupCode to_group_code(const string str) {
    return atoi(str.c_str());
}

vector<string> tokenize(const string str) {
    stringstream sstr(str);
    vector<string> tokens;
    string token;
    while(sstr >> token)
        tokens.push_back(token);
    return tokens;
}

vector<string> tokenize(const string str, const char delim) {
    stringstream sstr(str);
    vector<string> tokens;
    string token;
    while(getline(sstr, token, delim))
        tokens.push_back(token);
    return tokens;
}

map<CourseCode, string> get_course_names(string dict_addr) {
    map<CourseCode, string> course_names;

    fstream dict_stream(dict_addr);
    if (dict_stream.fail()) {
        cerr << "Invlaid <CourseNameDict.csv> address: " << dict_addr << endl;
        exit(EXIT_FAILURE);
    }
    {
        string dummy_str;
        dict_stream >> dummy_str;
    }
    while (!dict_stream.eof() && !dict_stream.fail()) {
        CourseCode code;
        string name;
        char dummy_char;
        dict_stream >> code >> dummy_char >> name;
        course_names[code] = name;
    }
    if (dict_stream.fail()) {
        cerr << "Invlaid <CourseNameDict.csv> structure: " << dict_addr << endl;
        exit(EXIT_FAILURE);
    }
    dict_stream.close();

    return course_names;
}

TimeSlot parse_time_slot(string weekday, string full_time) {
    const char time_delim = '-';
    static const map<string, TimeSlot::Weekday> weekday_dict = get_weekday_dict();
    static const map<string, TimeSlot::Time> time_dict = get_time_dict();

    TimeSlot time_slot;
    vector<string> times = tokenize(full_time, time_delim);
    if (times.size() != 2)
        throw invalid_argument("Invalid number of times per time slot");
    try {
        time_slot.weekday = weekday_dict.at(weekday);
        time_slot.start_time = time_dict.at(times[0]);
        time_slot.end_time = time_dict.at(times[1]);
        if (to_numerical(time_slot.start_time) >= to_numerical(time_slot.end_time))
            throw invalid_argument("Invalid time slot arg");
    } catch (out_of_range) {
        throw invalid_argument("Invalid time slot arg");
    }
    return time_slot;
}

Offering parse_offering(string str) {
    const char code_delim = '-';

    Offering offering;
    vector<string> tokens = tokenize(str);
    if (!tokens.size() || !(tokens.size() % 2))
        throw invalid_argument("Invalid number of offering args");
    vector<string> codes = tokenize(tokens[0], code_delim);
    if (codes.size() != 2)
        throw invalid_argument("Invalid offering code");
    offering.course_code = to_course_code(codes[0]);
    offering.group_code = to_group_code(codes[1]);
    for (size_t i = 1; i < tokens.size() - 1; i += 2)
        offering.time_slots.push_back(parse_time_slot(tokens[i], tokens[i + 1]));
    return offering;
}

vector<Offering> get_offerings(istream &istr) {
    vector<Offering> offerings;
    string offering;
    while (getline(istr, offering)) {
        try {
            offerings.push_back(parse_offering(offering));
        } catch (const invalid_argument &exc) {
            cerr << exc.what() << ". Try again..." << endl;
        }
    }
    return offerings;
}

pair<Programme, ProgrammeLimits> get_new_programme() {
    Programme programme;
    ProgrammeLimits first_empty;
    for (auto weekday : weekdays) {
        programme[weekday] = vector<ProgrammeRow>();
        first_empty[weekday] = map<TimeSlot::Time, size_t>();
        for (auto time_atom : time_atoms)
            first_empty[weekday][time_atom] = 0;
    }
    return pair<Programme, ProgrammeLimits> (programme, first_empty);
}

void sort(Programme &programme) {
    for (auto weekday : weekdays) {
        for (ProgrammeRow &row : programme.at(weekday))
            sort(row.begin(), row.end(), [](const ProgrammeCell &first_cell, const ProgrammeCell &second_cell) -> bool {
                return to_numerical(first_cell.first.start_time) < to_numerical(second_cell.first.start_time);
            });
    }
}

Programme schedule(const vector<Offering> &offerings) {
    pair<Programme, ProgrammeLimits> new_programme_package = get_new_programme();
    Programme programme = new_programme_package.first;
    ProgrammeLimits first_empty = new_programme_package.second;
    for (Offering const &offering : offerings) {
        for (TimeSlot const &time_slot : offering.time_slots) {
            vector<size_t> first_empties;
            auto start_time_iter = find(time_atoms.begin(), time_atoms.end(), time_slot.start_time);
            auto end_time_iter = find(time_atoms.begin(), time_atoms.end(), time_slot.end_time);
            for (
                auto time_atom = start_time_iter;
                time_atoms.size() && time_atom != time_atoms.end() && time_atom != end_time_iter;
                time_atom++
            )
                first_empties.push_back(first_empty[time_slot.weekday][*time_atom]);
            size_t max_first_empty = *max_element(first_empties.begin(), first_empties.end());
            for (size_t i = programme[time_slot.weekday].size(); i <= max_first_empty + 1; i++)
                programme[time_slot.weekday].push_back(ProgrammeRow());
            programme[time_slot.weekday][max_first_empty].push_back(ProgrammeCell(time_slot, offering));
            for (
                auto time_atom = start_time_iter;
                time_atoms.size() && time_atom != time_atoms.end() && time_atom != end_time_iter;
                time_atom++
            )
                first_empty[time_slot.weekday][*time_atom] = max_first_empty + 1;
        }
    }
    sort(programme);
    return programme;
}

void print_row_pref(ostream &ostr) {
    const string time_hour_mask = "hh";
    ostr << string(time_hour_mask.size(), ' ');
}

void print_row_borders(const ProgrammeRow &row, ostream &ostr,
        size_t cell_width, const char vertical_border, const char left_corner, const char right_corner) {
    print_row_pref(ostr);
    size_t cur = 0;
    for (ProgrammeCell cell : row) {
        ostr << setw((to_numerical(cell.first.start_time) - cur) * cell_width + 1) << right << left_corner;
        size_t width = (to_numerical(cell.first.end_time) - to_numerical(cell.first.start_time));
        ostr << setfill(vertical_border) << setw(width * cell_width - 1) << right << right_corner << setfill(' ');
        cur = to_numerical(cell.first.end_time);
    }
    ostr << endl;
}

void print_row_contents(const ProgrammeRow &row, const map<CourseCode, string> &course_names, ostream &ostr,
        size_t cell_width, const char vertical_border) {
    print_row_pref(ostr);
    size_t cur = 0;
    for (ProgrammeCell cell : row) {
        ostr << setw((to_numerical(cell.first.start_time) - cur) * cell_width + 1) << right << vertical_border;
        size_t width = (to_numerical(cell.first.end_time) - to_numerical(cell.first.start_time));
        size_t cnt_width = width * cell_width - 2;
        string cnt;
        try {
            cnt = course_names.at(cell.second.course_code) + " (" + to_string(cell.second.group_code) + ")";
        } catch (out_of_range) {
            throw invalid_argument("Invalid course code");
        }
        if (cnt.size() > cnt_width)
            throw invalid_argument("Long course name");
        size_t space_after_cnt_width = (cnt_width - cnt.size()) / 2;
        ostr << setw(cnt_width - space_after_cnt_width) << right << cnt
             << setw(space_after_cnt_width + 1) << right << vertical_border;
        cur = to_numerical(cell.first.end_time);
    }
    ostr << endl;
}

void print_row(const ProgrammeRow &row, const map<CourseCode, string> &course_names, ostream &ostr, size_t cell_width) {
    const char vertical_border = '|';
    const char horizontal_border = '-';
    const char top_left_corner = '+';
    const char top_right_corner = '+';
    const char bottom_left_corner = '+';
    const char bottom_right_corner = '+';
    print_row_borders(row, ostr, cell_width, horizontal_border, top_left_corner, top_right_corner);
    print_row_contents(row, course_names, ostr, cell_width, vertical_border);
    print_row_borders(row, ostr, cell_width, horizontal_border, bottom_left_corner, bottom_right_corner);
}

void print_programme(const Programme &programme, const map<CourseCode, string> &course_names, string title, ostream &ostr) {
    const size_t cell_width = 10;
    const string title_pref = "# ";
    const string weekday_pref = "## ";
    const char timeline_border = '_';
    const string time_mask = "hh:mm";

    ostr << title_pref << title << endl << endl;
    for (auto weekday : weekdays) {
        ostr << weekday_pref << to_string(weekday) << endl << endl;
        bool is_first_time = true;
        for (auto time_atom : time_atoms) {
            if (!is_first_time)
                ostr << setw(cell_width) << right;
            ostr << to_string(time_atom);
            is_first_time = false;
        }
        ostr << endl;
        ostr << setfill(timeline_border) << setw(cell_width * (time_atoms.size() - 1) + string(time_mask).size())
             << left << timeline_border << setfill(' ') << endl;
        for (ProgrammeRow row : programme.at(weekday))
            if (row.size())
                print_row(row, course_names, ostr, cell_width);
        ostr << endl;
    }
}

int main(int argc, char const *argv[])
{
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <CourseNameDict.csv> <Title>" << endl;
        return EXIT_FAILURE;
    }

    try {
        print_programme(schedule(get_offerings(cin)), get_course_names(argv[1]), argv[2], cout);
    } catch (const invalid_argument &exc) {
        cerr << exc.what() << "." << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
