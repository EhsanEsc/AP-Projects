// In The Name Of God

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<map>

using namespace std ;

#define NUMBER_OF_TIMES 28
#define NUMBER_OF_SPACES 5
#define MAX_COURSES 222
#define NUMBER_OF_DAYS 7
#define TIME_LEN 5

#define NUMBER_OF_PHASES 5
#define NUMBER_OF_CSV_INPUT 2
#define NUMBER_OF_IDS 2
#define LESSON_ID_LEN 7
#define LESSON_GROUP_LEN 2

#define DAYS_FULLNAME {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"}
#define DAYS_SHORTNAME {"SAT","SUN","MON","TUE","WED","THU","FRI"}

typedef char* Address ;
typedef vector<string> Words ;
typedef map<string,string> LessonTable ;
typedef map<string,int> TimeTable ;

#define DEBUG_MODE 0
#define PROGRAM_PHASES {"READING FROM CSV","GETTING COURSES","PRE PROCESS","PROCESS","OUTPUT"}
#define PHASE_GETTING_CSV 0
#define PHASE_GETTING_COURSES 1
#define PHASE_PRE_PROCSS 2
#define PHASE_PROCESS 3
#define PHASE_OUTPUT 4

#define ERROR_FILE "FILE COULDN'T BE OPEN ! "
#define ERROR_WRONGFORMAT "YOUR INPUT HAS WRONG FOMRAT ! "

#define STARTING_TIME  "07:00"
#define FINISHING_TIME "20:00"

#define CORNER_CHAR '+'
#define BORDER_CHAR '-'
#define SIDE_CHAR '|'
#define LINE_CHAR '_'
#define SIGN_CHAR '#'
#define CSV_SEPERATOR_CHAR ','
#define TIME_SEPERATOR_CHAR '-'
#define ID_SEPERATOR_CHAR '-'
#define TIME_ENTITY_SEPERATOR_CHAR ':'

#define CSV_TITLE "id,alias"

#define READING_FROM_FILE 0
#define INPUT_ADDRESS "big/input.txt"
#define OUTPUT_ADDRESS "big/oo.txt"

void raiseError(int error_id, string message)
{
  if(!DEBUG_MODE)
    return ;

  string phases[NUMBER_OF_PHASES] = PROGRAM_PHASES ;
  string error_phase = phases[error_id] ;

  cout << "@@@ Error in " << error_phase << " phase @@@" << endl ;
  cout << "@@@ Error message is " << message << " @@@" << endl ;

  exit(0) ;
  return ;
}

struct ClassTime
{
    string day ;
    string start_time ;
    string finish_time ;
};

struct Course
{
  string id_lesson ;
  string id_group ;
  vector<ClassTime> times ;
};

typedef pair<Course,ClassTime>  Data ;

vector<string> splitWords(string line , char seperator)
{
  vector<string> res ;
  string word = "" ;

  for(int i=0 ; i<line.size() ; i++)
  {
    if(line[i] == seperator)
    {
      res.push_back(word) ;
      word = "" ;
    }
    else
    {
      word += line[i] ;
    }
  }
  res.push_back(word) ;

  return res ;
}

void setCourseList(Address address , LessonTable& course_list)
{
  ifstream fl(address) ;
  string line ;

  if(!fl)
    raiseError(PHASE_GETTING_CSV , ERROR_FILE) ;

  while(getline(fl , line))
  {
      if(line == CSV_TITLE)
        continue ;

      Words words = splitWords(line , CSV_SEPERATOR_CHAR) ;
      if(words.size() != NUMBER_OF_CSV_INPUT)
        raiseError(PHASE_GETTING_CSV , ERROR_WRONGFORMAT) ;

      string id = words[0] ;
      string course_name = words[1] ;

      course_list[id] = course_name ;
  }
}



bool checkFormatTime(string tm)
{
  if(tm.size() != TIME_LEN)
    return true ;
  if(!isdigit(tm[0]) || !isdigit(tm[1]) || !isdigit(tm[3]) || !isdigit(tm[4]))
    return true ;
  if(tm[0]>'2' || tm[1]>'9' || tm[2]!=TIME_ENTITY_SEPERATOR_CHAR || (tm[3]!='0' && tm[3]!='3') || tm[4]!='0')
    return true ;
  if(tm<STARTING_TIME || tm>FINISHING_TIME)
    return true ;
  return false ;
}

bool checkFormatID(vector<string> ids)
{
  if(ids.size() != NUMBER_OF_IDS)
    return true ;
  if(ids[0].size() != LESSON_ID_LEN || ids[1].size() != LESSON_GROUP_LEN)
    return true ;
  return false ;
}

bool checkFormatLineInput(vector<string> line)
{
  if(line.size()%2 == 0)
    return true ;
  return false ;
}

bool checkFormat(vector<string> nums)
{
  for(auto tm : nums)
    if(checkFormatTime(tm))
      return true ;
  return false;
}

void getCourses(vector<Course>& courses)
{
  string ln ;
  while(getline(cin , ln))
  {
    Words line = splitWords(ln , ' ') ;
    Words ids = splitWords(line[0] , ID_SEPERATOR_CHAR) ;
    Course cs ;

    if(checkFormatLineInput(line))
      raiseError(PHASE_GETTING_COURSES , ERROR_WRONGFORMAT) ;
    if(checkFormatID(ids))
      raiseError(PHASE_GETTING_COURSES , ERROR_WRONGFORMAT) ;

    cs.id_lesson = ids[0] ;
    cs.id_group  = ids[1] ;

    for(int i=1 ; i<line.size() ; i+=2)
    {
      ClassTime ct ;
      vector<string> tm = splitWords(line[i+1] , TIME_SEPERATOR_CHAR) ;

      if(checkFormat(tm))
        raiseError(PHASE_GETTING_COURSES , ERROR_WRONGFORMAT) ;

      ct.day = line[i] ;
      ct.start_time  = tm[0] ;
      ct.finish_time = tm[1] ;

      cs.times.push_back(ct) ;
    }

    courses.push_back(cs) ;
  }
}

vector< Data > importCoursesToDay(string day_name , vector<Course>courses)
{
  vector< Data > res ;

  for(auto cs:courses)
    for(auto ct:cs.times)
      if(ct.day == day_name)
        res.push_back(make_pair(cs,ct)) ;

  return res ;
}

void add30min(string& tm)
{
  if(tm[3] == '0')
  {
    tm[3] = '3' ;
  }
  else
  {
    tm[3] = '0' ;
    if(tm[1] != '9')
      tm[1] ++ ;
    else
    {
      tm[1] = '0' ;
      tm[0] ++ ;
    }
  }
}

string buildMultiChar(int cnt , char c)
{
  string res = "" ;
  for(int i=0 ; i<cnt ; i++)
    res += c ;
  return res;
}

void printTimes()
{
  string tm = STARTING_TIME ;
  for(int i=0 ; i<NUMBER_OF_TIMES ; i++)
  {
    cout << tm ;
    if(i != NUMBER_OF_TIMES-1)
      cout << buildMultiChar(NUMBER_OF_SPACES , ' ') ;

    add30min(tm) ;
  }
  cout << endl ;
}

void printLine()
{
  int line_len = (NUMBER_OF_TIMES-1)*(NUMBER_OF_SPACES+TIME_LEN)+TIME_LEN ;
  cout << buildMultiChar(line_len , LINE_CHAR) ;
  cout << endl ;
}

bool conflict(ClassTime a , ClassTime b , string day_name)
{
  if(max(a.start_time , b.start_time) < min(a.finish_time , b.finish_time))
    return true ;
  else
    return false ;
}

void setLevels(int levels[MAX_COURSES] , vector< Data > day_courses , string day_name)
{
  for(int i=0 ; i<MAX_COURSES ; i++)
    levels[i] = -1 ;

  for(int i=0 ; i<day_courses.size() ; i++)
  {
    levels[i] = 0 ;
    for(int j=0 ; j<i ; j++)
    {
      if(conflict(day_courses[i].second , day_courses[j].second , day_name))
        levels[i] = levels[j] + 1;
    }
  }
}

string fixLeadingZeroes(string str)
{
  int index = 0;
  while(index < str.size() && str[index] == '0')
  {
    index++ ;
  }
  return str.substr(index) ;
}

void setTimeIndex(TimeTable& time_index)
{
  int ct = 0 ;
  string current_time = STARTING_TIME ;
  while(current_time <= FINISHING_TIME)
  {
    time_index[current_time] = ct ;
    ct++ ;
    add30min(current_time) ;
  }
}

void setSides(string& line1 , string& line2 , string& line3 , int st , int en)
{
  line1[st+2] = CORNER_CHAR ;
  line2[st+2] = SIDE_CHAR ;
  line3[st+2] = CORNER_CHAR ;

  line1[en+1] = CORNER_CHAR ;
  line2[en+1] = SIDE_CHAR ;
  line3[en+1] = CORNER_CHAR ;

  for(int k=st+3 ; k<en+1 ; k++)
    line1[k] = line3[k] = BORDER_CHAR ;
}

string buildName(LessonTable course_list , Course cs)
{
  string lesson_name = course_list[cs.id_lesson] ;
  lesson_name += " (" ;
  lesson_name += fixLeadingZeroes(cs.id_group) + ")" ;
  return lesson_name ;
}

void setWord(string& line2 , string lesson_name , int st , int en)
{
  int ted = en-st-lesson_name.size()-2 ;
  int t1 = (ted+1)/2 ;
  for(int k=st+3+t1,w=0 ; w<lesson_name.size() ; w++,k++)
    line2[k] = lesson_name[w] ;
}

int findMaxLevel(int levels[MAX_COURSES])
{
  int max_lvl = -1 ;
  for(int i=0 ; i<MAX_COURSES ; i++)
    max_lvl = max(max_lvl , levels[i]) ;
  return max_lvl ;
}

void deleteExtraSpaces(string &str)
{
  for(int i=str.size()-1;i>=0;i--)
  {
    if(str[i]!=' ')
    {
      str = str.substr(0,i+1) ;
      return ;
    }
  }
  str = "" ;
  return ;
}

void printLessons(int levels[MAX_COURSES] , vector< Data > day_courses ,
                  LessonTable course_list , string day_name , TimeTable time_index)
{
  int max_lvl = findMaxLevel(levels) ;

  for(int i=0 ; i<=max_lvl ; i++)
  {
    string line1,line2,line3 ;
    int line_len = (NUMBER_OF_TIMES-1)*(NUMBER_OF_SPACES+TIME_LEN)+TIME_LEN ;
    line1=line2=line3=buildMultiChar(line_len , ' ');

    for(int j=0 ; j<day_courses.size() ; j++)
    {
      if(levels[j]!=i)
        continue ;

      Course cs = day_courses[j].first ;
      ClassTime ct = day_courses[j].second ;
      int st = time_index[ct.start_time]  * (NUMBER_OF_SPACES+TIME_LEN) ;
      int en = time_index[ct.finish_time] * (NUMBER_OF_SPACES+TIME_LEN) ;
      string lesson_name = buildName(course_list , cs) ;

      setSides(line1 , line2 , line3 , st , en) ;
      setWord(line2 , lesson_name , st , en) ;
    }

    deleteExtraSpaces(line1) ;
    deleteExtraSpaces(line2) ;
    deleteExtraSpaces(line3) ;

    cout << line1 << endl ;
    cout << line2 << endl ;
    cout << line3 << endl ;
  }
}

int main(int argv , char* argc[])
{
  if(READING_FROM_FILE)
  {
    freopen(INPUT_ADDRESS  , "r" , stdin)  ;
    freopen(OUTPUT_ADDRESS , "w" , stdout) ;
  }

  string days_full_name[NUMBER_OF_DAYS]  =  DAYS_FULLNAME ;
  string days_short_name[NUMBER_OF_DAYS] = DAYS_SHORTNAME ;
  vector< Data > days[NUMBER_OF_DAYS] ;
  vector<Course> courses ;
  LessonTable course_list ;
  TimeTable time_index ;
  int levels[MAX_COURSES] ;
  string title ;

  setTimeIndex(time_index) ;

  setCourseList(argc[1] , course_list) ;
  title = argc[2] ;

  getCourses(courses) ;

  for(int i=0 ; i<NUMBER_OF_DAYS ; i++)
    days[i] = importCoursesToDay(days_short_name[i] , courses) ;

  cout << SIGN_CHAR << " " << title << endl << endl ;

  for(int i=0 ; i<NUMBER_OF_DAYS ; i++)
  {
    cout << SIGN_CHAR << SIGN_CHAR << " " << days_full_name[i] << endl << endl ;

    printTimes() ;
    printLine() ;

    setLevels(levels , days[i] , days_short_name[i]) ;
    printLessons(levels , days[i] , course_list , days_short_name[i] , time_index) ;
    cout << endl ;
  }

  return 0 ;
}
