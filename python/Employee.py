class Employee:
    def __init__(self, idNum: int, name: str, dept: str, age: int, score: float, salary: int):
        self.idNum = idNum
        self.name = name
        self.dept = dept
        self.age = age
        self.score = score
        self.salary = salary
    
    @staticmethod
    def createEmployee(record: str) -> Employee:
        recordSplit = record.split(",")
        return Employee(int(recordSplit[0]), recordSplit[1], recordSplit[2], int(recordSplit[3]), float(recordSplit[4]), int(recordSplit[5]))
    
    def rating(self) -> str:
        if self.score > 90:
            return "Excellent"
        elif self.score > 80:
            return "Good"
        elif self.score > 70:
            return "Fair"
        else:
            return "Bad"
    
    def __lt__(self, other: Employee) -> bool:
        return self.idNum < other.idNum
    
    def __eq__(self, other: Employee) -> bool:
        return self.idNum == other.idNum and self.name == other.name and self.dept == other.dept and self.age == other.age and self.score == other.score and self.salary == other.salary
    
    def __repr__(self) -> str:
        return f"Name:{self.name}\nID:{self.idNum}\nDepartment:{self.dept}\nRating:{self.rating()}\nAge:{self.age}\nScore:{round(self.score, 2)}\nSalary:{round(self.salary, 2)}\n"
