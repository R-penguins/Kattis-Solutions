/// Baylor Competitive Learning course BASIC Interpreter
/// 0.01s
/// simulation
#include <bits/stdc++.h>
using namespace std;

array<int, 26> reg;
int pc = 0;
map<int, int> label_lineno;

void parse_op(string& str, bool& usereg, int& op)
{
  if (isalpha(str[0])) {
    usereg = true;
    op = str[0] - 'A';
  } else
    op = stoi(str);
}

struct Statement {
  Statement(int label)
      : label(label)
  {
  }
  virtual void execute() = 0;
  int label;
};

struct Assignment : Statement {
  Assignment(int label, string& str)
      : Statement(label)
  {
    stringstream ss(str);
    char lhs;
    string op1_str, op2_str, garbage;
    ss >> lhs >> garbage >> op1_str;
    lhs_reg = lhs - 'A';
    parse_op(op1_str, usereg1, op1);
    if (ss >> op >> op2_str)
      parse_op(op2_str, usereg2, op2);
  }
  void execute() override
  {
    int op1_val = usereg1 ? reg[op1] : op1;
    int op2_val = usereg2 ? reg[op2] : op2;
    int rhs;
    switch (op) {
    case '=':
      rhs = op1_val;
      break;
    case '+':
      rhs = op1_val + op2_val;
      break;
    case '-':
      rhs = op1_val - op2_val;
      break;
    case '*':
      rhs = op1_val * op2_val;
      break;
    case '/':
      rhs = op1_val / op2_val;
      break;
    default:
      break;
    }
    reg[lhs_reg] = rhs;
    ++pc;
  }
  int lhs_reg, op1, op2;
  bool usereg1 = false, usereg2 = false;
  char op = '=';
};

struct Conditional : Statement {
  Conditional(int label, string& str)
      : Statement(label)
  {
    stringstream ss(str);
    string op1_str, op2_str, cmp_str, garbage;
    ss >> op1_str >> cmp_str >> op2_str >> garbage >> garbage >> goto_label;
    for (char c : cmp_str)
      cmp += c;
    parse_op(op1_str, usereg1, op1);
    parse_op(op2_str, usereg2, op2);
  }
  void execute() override
  {
    int op1_val = usereg1 ? reg[op1] : op1;
    int op2_val = usereg2 ? reg[op2] : op2;
    bool statement_istrue;
    switch (cmp) {
    case '=':
      statement_istrue = op1_val == op2_val;
      break;
    case '>':
      statement_istrue = op1_val > op2_val;
      break;
    case '<':
      statement_istrue = op1_val < op2_val;
      break;
    case '<' + '>':
      statement_istrue = op1_val != op2_val;
      break;
    case '<' + '=':
      statement_istrue = op1_val <= op2_val;
      break;
    case '>' + '=':
      statement_istrue = op1_val >= op2_val;
      break;
    default:
      break;
    }
    if (statement_istrue)
      pc = label_lineno[goto_label];
    else
      ++pc;
  }
  int op1, op2, goto_label;
  bool usereg1 = false, usereg2 = false;
  char cmp = 0;
};

struct Print : Statement {
  Print(int label, string& str, bool newline)
      : Statement(label)
      , newline(newline)
  {
    if (str[1] != '"')
      var = str[1] - 'A';
    else
      literal_string = str.substr(2, str.size() - 3);
  }
  void execute() override
  {
    if (var != -1)
      cout << reg[var];
    else
      cout << literal_string;
    if (newline)
      cout << '\n';
    ++pc;
  }
  bool newline;
  int var = -1;
  string literal_string;
};

vector<unique_ptr<Statement>> program;
bool operator<(const unique_ptr<Statement>& lhs, const unique_ptr<Statement>& rhs)
{
  return lhs->label < rhs->label;
}

void parse()
{
  int label;
  string cmd, str;
  while (cin >> label >> cmd) {
    getline(cin, str);
    if (cmd[0] == 'L') { // LET
      program.emplace_back(make_unique<Assignment>(label, str));
    } else if (cmd[0] == 'I') { // IF
      program.emplace_back(make_unique<Conditional>(label, str));
    } else { // PRINT / PRINTLN
      program.emplace_back(make_unique<Print>(label, str, cmd.size() > 5));
    }
  }
  sort(program.begin(), program.end());
  for (int i = 0; i < program.size(); ++i)
    label_lineno[program[i]->label] = i;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  parse();
  while (pc < program.size())
    program[pc]->execute();

  return 0;
}
