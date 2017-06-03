# DaHomework
## 注意事项
### 字典的拷贝
BasicDict,UserDict拷贝效率很低
### Debug时使用dict-small.json而不是dict.json
dict-small.json是缩小的字典，在Debug模式中dict.json的读取非常慢
### 不要使用Notepad编辑词库
Notepad会自动储存为UTF-8 with BOM格式，程序没有做BOM的预处理。必须保存为UTF-8 without BOM格式。
### Resource Files存储在\Palabra\res下
Resource Files与Source Files分离存储