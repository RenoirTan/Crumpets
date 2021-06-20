from dataclasses import dataclass
import typing as t
import sys
if sys.version_info < (3, 10):
    print("This script requires python version ^3.10 to work.")
    print("If you see this message, then SyntaxError failed at its job.")

@dataclass
class Point:
    x: int
    y: int


p1 = Point(1, 2)

match p1:
    case Point(1, 2):
        print("yes")
    case _:
        print("no")
