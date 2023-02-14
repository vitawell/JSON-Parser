#include <iostream>
#include <stack>
#include <string>
#include <vector>

class JSON {
 public:
  JSON() {}
  virtual ~JSON() {}

  // 读取并解析 JSON 数据
  bool parse(const std::string& json) {
    // 数据是否合法
    bool success = true;
    // 当前解析位置
    int index = 0;
    // 当前缩进级别
    int indent_level = 0;

    while (index < json.length() && success) {
      char c = json[index];
      switch (c) {
        case '{':
        case '[':
          // 如果是对象或数组，则进入下一级缩进
          indent_level++;
          // 输出缩进
          printIndent(indent_level);
          std::cout << c << std::endl;
          break;
        case '}':
        case ']':
          // 如果是对象或数组，则退回上一级缩进
          indent_level--;
          // 输出缩进
          printIndent(indent_level);
          std::cout << c << std::endl;
          break;
        case ',':
          // 如果是逗号，则换行并输出缩进
          std::cout << c << std::endl;
          printIndent(indent_level);
          break;
        case ':':
          // 如果是冒号，则输出并空格
          std::cout << ": ";
          break;
        default:
          // 否则直接输出
          std::cout << c;
          break;
      }
      index++;
    }
    return success;
  }

 private:
  // 输出缩进
  void printIndent(int indent_level) {
    for (int i = 0; i < indent_level; i++) {
      std::cout << "    ";
    }
  }
};

int main(int argc, char* argv[]) {
  JSON json;
  std::string data = "{\"foo\":\"bar\",\"baz\":[1,2,3]}";
  if (json.parse(data)) {
    std::cout << "Successfully parsed JSON data." << std::endl
