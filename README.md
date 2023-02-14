# JSON-Parser

用C++实现一个json parser，不依赖且不参照其他json库，要求能读取标淮json格式数据，进行格式化输出且带缩进。

![Image text](https://raw.github.com/vitawell/JSON-Parser/main/json.png)

使用chatGPT得到代码0.cpp，缩进有问题。

修改后1.cpp，输出成功。

![Image text](https://raw.github.com/vitawell/JSON-Parser/main/json1.png)

但是，还有一些细节需要注意：

该代码仅支持有限的 JSON 格式，例如，仅支持简单的字符串、数字、布尔值和 null 值等。如果 JSON 数据中含有特殊字符，则可能无法正确解析。
对于数字，该代码不会对其进行任何格式化输出，也不会对其进行任何特殊处理。
