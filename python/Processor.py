from Employee import Employee

class Processor:
    def __init__(self, fname: str):
        self.fname = fname
        self.employees = {}
        self.readFile()

    def readFile(self) -> None:
        try:
            with open(self.fname, 'r') as file:
                for line in file:
                    line = line.strip()
                
                    newEmployee: Employee = Employee.createEmployee(line)

                    if newEmployee.dept not in self.employees:
                        self.employees[newEmployee.dept] = []

                    self.employees[newEmployee.dept].append(newEmployee)

                keys = list(self.employees.keys())

                for key in keys:
                    self.employees[key].sort()

        except IOError:
            print("cannot open file")
            quit()
    
    def printAllEmployees(self) -> None:
        keys = list(self.employees.keys())
        keys.sort()

        for key in keys:
            for employee in self.employees[key]:
                print(str(employee))
    
    def findEmployee(self, searched: str) -> list[Employee]:
        foundEmployees = []

        keys = list(self.employees.keys())

        for key in keys:
            for employee in self.employees[key]:
                if employee.name.lower().find(searched.lower()) != -1:
                    foundEmployees.append(employee)
    
        return foundEmployees
    
    def printSearchResult(self, searched: str) -> None:
        foundEmployees = self.findEmployee(searched)

        if len(foundEmployees) == 0:
            print("No result")
        else:
            print(f"{len(foundEmployees)} employee/s found")
            for employee in foundEmployees:
                print(str(employee))

    def departmentStats(self, dept: str) -> str:
        return f"{dept} Department:\n- Employees: {len(self.employees[dept])}\n- Average Performance: {self.calculate_department_average(dept, 'score'):.2f}\n- Average Salary: {self.calculate_department_average(dept, 'salary'):.2f}\n"

    def calculate_department_average(self, department: str, criteria: str) -> float:
        depEmployees = self.employees[department]
        depSize = len(depEmployees)

        if criteria == "score":
            totalScore = 0

            for employee in depEmployees:
                totalScore += employee.score
            
            return round(totalScore / depSize, 2)
        else:
            totalSalary = 0

            for employee in depEmployees:
                totalSalary += employee.salary
            
            return round(totalSalary / depSize, 2)
    
    def totalAvg(self, criteria: str) -> float:
        keys = list(self.employees.keys())
        depCount = len(keys)
        averages = 0

        for key in keys:
            averages += self.calculate_department_average(key, criteria)

        return round(averages / depCount, 2)
    
    def generateReport(self) -> None:
        with open(f'report_{self.fname}', 'w') as file:
            file.write("=================\n")
            file.write(f"Generated from: {self.fname}\n\n")
            file.write("Company Statistics:\n")
            employeeTotal = 0
            keys = list(self.employees.keys())
            keys.sort()

            for key in keys:
                employeeTotal += len(self.employees[key])

            file.write(f"Total Employees: {employeeTotal}\n")
            file.write(f"Overall Average Performance: {self.totalAvg('score'):.2f}\n")
            file.write(f"Average Salary: {self.totalAvg('salary'):.2f}\n\n")
            file.write("Department Breakdown\n")
            file.write("-------------\n")

            for key in keys:
                file.write(self.departmentStats(key))
                file.write("\n")
    
    def menu(self) -> None:
        print("Choice 1 For searching users")
        print("Choice 2 For generating report")
        print("Choice 3 For printing all employees")
        print("Choice 4 For exiting")
        
        userInput = 0
        userInputStr = ""

        while userInput != 4:
            print("Enter choice")
            userInput = int(input())

            if userInput == 1:
                print("Enter searched string")
                userInputStr = input()
                self.printSearchResult(userInputStr)
            elif userInput == 2:
                self.generateReport()
                print("Report generated\n")
            elif userInput == 3:
                self.printAllEmployees()
                print("All employees are printed\n")
            elif userInput == 4:
                print("Done")

# main method will create instance of Processor. 
# then it will run menu method 
if __name__ == "__main__": 
    print("Enter file name") 
    fname = input() 
    employee_processor = Processor(fname) 
    employee_processor.menu()