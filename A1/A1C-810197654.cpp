// In The Name Of God

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

const char SIGN_INPUT = '?';
const char SIGN_OUTPUT = '!';
const char SIGN_ASSIGMENT = '=';
const char SIGN_PLUS = '+';
const char SIGN_MINUS = '-';

const vector<char> sign_operators { SIGN_INPUT , SIGN_OUTPUT , SIGN_ASSIGMENT ,
  SIGN_PLUS , SIGN_MINUS };

const string COMMAND_FINISH = "run";

const string ERROR_SYNTAX = "Syntax error at line ";
const string ERROR_END_INPUT = "Unexpected end of input";

const int EXIT_SUCESS = 0;

typedef vector<vector<string> > Commands;
typedef vector<string> Command;

enum class CommandType
{
  empty_line = 0,
  input,
  output,
  state,
  finish,
  wrong_command = -1
};

template<typename T>
bool is_contain(vector<T> container , T val)
{
  for(auto ct : container)
    if(ct == val)
      return true;
  return false;
}

bool is_word(string str)
{
  return str.size() &&
    isalpha(str[0]);
}

bool is_number(string str)
{
  if(str.size() == 0)
    return false;
  for(char c:str)
    if(!isdigit(c))
      return false;
  return true;
}

bool is_empty_line(Command command)
{
  return command.empty();
}

bool is_input(Command command)
{
  return !command.empty() &&
    command[0][0]==SIGN_INPUT;
}

bool is_output(Command command)
{
  return !command.empty() &&
    command[0][0]==SIGN_OUTPUT;
}

bool is_finish(Command command)
{
  return command.size()==1 &&
    command[0]==COMMAND_FINISH;
}

bool is_state(Command command)
{
  return command.size()>=2 &&
    is_word(command[0]);
}

CommandType determine_type(Command command)
{
  if(is_empty_line(command))
    return CommandType::empty_line;
  else if(is_finish(command))
    return CommandType::finish;
  else if(is_input(command))
    return CommandType::input;
  else if(is_output(command))
    return CommandType::output;
  else if(is_state(command))
    return CommandType::state;
  else
    return CommandType::wrong_command;
}

bool is_operator(string str)
{
  return str.size()==1 &&
    (str[0] == SIGN_PLUS || str[0] == SIGN_MINUS);
}

void report_syntax_error(int line_number)
{
	cout << ERROR_SYNTAX << line_number << endl ;
	exit(EXIT_SUCESS);
}

void report_end_input_error()
{
	cout << ERROR_END_INPUT << endl ;
	exit(EXIT_SUCESS);
}

int get_value(string str,map<string,int> values)
{
  if(is_word(str))
    return values[str];
  if(is_number(str))
    return stoi(str);
  return 0;
}

Command split_line(string str)
{
	Command res;

  for(int st=0 ; st<str.size() ; st++)
  {
    int en=st;
    if(str[st] == ' '){
      continue;
    } else if(isdigit(str[st])){
      while(en<str.size() && isdigit(str[en]))
			{
				en++ ;
			}
    } else if(isalpha(str[st])){
      while(en<str.size() && (isdigit(str[en]) || isalpha(str[en])) )
			{
				en++ ;
			}
    } else if(is_contain(sign_operators , str[st])){
      en++;
    } else {
      en++;
    }

    string word = str.substr(st,en-st);
    res.push_back(word);
    st = en-1;
  }

  return res;
}

vector<string> get_programme()
{
  vector<string> commands;
  string str;

  while(getline(cin,str))
  {
    commands.push_back(str);
    int sz = COMMAND_FINISH.size();
    if(str.substr(0,sz) == COMMAND_FINISH)
      break;
  }

  return commands;
}

Commands split_commands(vector<string> raw_commands)
{
  Commands commands;
  for(string str : raw_commands)
  {
    Command cm = split_line(str);
    commands.push_back(cm);
  }
  return commands;
}

bool validate_input(Command command)
{
  return command.size()==2 &&
    command[0][0]==SIGN_INPUT &&
    is_word(command[1]);
}

bool validate_output(Command command)
{
  return command.size()==2 &&
    command[0][0]==SIGN_OUTPUT &&
    is_word(command[1]);
}

bool validate_finish(Command command)
{
  return command.size()==1 &&
    command[0]==COMMAND_FINISH;
}

bool validate_state(Command command)
{
  for(int i=2 ; i<command.size() ; i+=2)
    if(!is_word(command[i]) && !is_number(command[i]))
      return false;
  for(int i=3 ; i<command.size() ; i+=2)
    if(!is_operator(command[i]))
      return false;
  return command.size()>=3 &&
    is_word(command[0]) &&
    command[1][0]==SIGN_ASSIGMENT &&
    command.size()%2 == 1;
}

void valididate_commands(Commands commands , vector<CommandType> commands_type)
{
  for(int line_number=1 ; line_number<=commands.size() ; line_number++)
  {
    Command command = commands[line_number-1];
    CommandType type = commands_type[line_number-1];

    if(type == CommandType::wrong_command)
      report_syntax_error(line_number);
    else if(type == CommandType::input && !validate_input(command))
      report_syntax_error(line_number);
    else if(type == CommandType::output && !validate_output(command))
      report_syntax_error(line_number);
    else if(type == CommandType::state && !validate_state(command))
      report_syntax_error(line_number);
    else if(type == CommandType::finish && !validate_finish(command))
      report_syntax_error(line_number);
    if(line_number == commands.size() && type != CommandType::finish)
      report_syntax_error(line_number);
  }
}

vector<int> get_inputs()
{
  vector<int> inputs;
  int num;
  while(cin>>num)
  {
    inputs.push_back(num);
  }
  reverse(inputs.begin(),inputs.end());
  return inputs;
}

int get_number(vector<int>& inputs)
{
  if(inputs.empty())
    report_end_input_error();
  int num = inputs.back();
  inputs.pop_back();
  return num;
}

int calc_state(Command command , map<string,int> values)
{
  int res = get_value(command[2] , values);
  for(int i=4 ; i<command.size() ; i+=2)
  {
    if(command[i-1][0] == SIGN_PLUS)
      res += get_value(command[i] , values);
    else if(command[i-1][0] == SIGN_MINUS)
      res -= get_value(command[i] , values);
  }
  return res;
}

void run_programme(Commands commands , vector<CommandType> commands_type , vector<int> inputs)
{
  map<string,int> values;

  for(int i=0 ; i<commands.size() ; i++)
  {
    Command command = commands[i];
    CommandType type = commands_type[i];

    if(type == CommandType::input){
      values[command[1]] = get_number(inputs);
    } else if(type == CommandType::output){
      cout << values[command[1]] << endl;
    } else if(type == CommandType::state){
      values[command[0]] = calc_state(command , values);
    }
  }
}

vector<CommandType> determine_commands_type(Commands commands)
{
  vector<CommandType> res;
  for(Command cm : commands)
    res.push_back(determine_type(cm));
  return res;
}

int main()
{
  vector<string>  commands_raw = get_programme();
  Commands commands = split_commands(commands_raw);

  vector<CommandType> commands_type = determine_commands_type(commands);
  valididate_commands(commands , commands_type);

  vector<int> inputs = get_inputs();

  run_programme(commands , commands_type , inputs);

	return EXIT_SUCESS;
}
