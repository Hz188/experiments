from dataclasses import dataclass, field
from typing import List

@dataclass
class Person:
    name: str
    age: int = 30  # 默认值
    hobbies: List[str] = field(default_factory=list)  # 默认工厂，避免可变默认参数陷阱
    is_employed: bool = field(default=True, metadata={"info": "Employment status"})
    _salary: float = field(repr=False, default=50000.0)  # 不在repr中显示的私有字段

    def birthday(self):
        self.age += 1

    @property
    def salary(self):
        return self._salary

    @salary.setter
    def salary(self, value):
        if value < 0:
            raise ValueError("Salary cannot be negative")
        self._salary = value

# 使用示例
p = Person(name="Alice")
print(p)  # Person(name='Alice', age=30, hobbies=[], is_employed=True)
p.hobbies.append("reading")
p.birthday()
p.salary = 60000
print(p.age)  # 31
print(p.salary)  # 60000
print(p.__dataclass_fields__["is_employed"].metadata)  # {'info': 'Employment status'}

'''
功能说明
1. ⁠@dataclass
    自动生成__init__,__repr__,__eq__等方法
2. age: int = 30
    可以直接在字段定义时赋值
3. default_factory
    用于可变类型字段，避免共享同一个默认对象
4. field
    提供更多字段定制，如 repr=False 隐藏字段，添加元数据等
5. 私有字段
    通过命名前加下划线，结合 repr=False 隐藏
6. 属性方法
    结合 @property 实现字段的访问控制
7. 元数据
    通过 metadata 参数添加元数据，可以通过 __dataclass_fields__ 获取
'''