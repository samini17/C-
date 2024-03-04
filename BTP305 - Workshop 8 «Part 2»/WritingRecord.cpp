//name: Nahal Mousavi
//email: nmousavi4@myseneca.ca
//Student ID: 133828178
//date: nov,24, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.//

#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		
		for (size_t i = 0; i < emp.size(); i++)
		{
			for (size_t j = 0; j < sal.size(); j++)
			{
				//if both of ids are equal
				if (emp[i].id == sal[j].id)
				{
					EmployeeWage* wage = new EmployeeWage(emp[i].name, sal[j].salary);

					//catch if an expression is thrown from the rangeValidator method
					try
					{
						wage->rangeValidator();
					}
					//catch that exception to delete the dynamic memory 
					//and then throw that exception again to be caught by the main method
					catch (const std::string& ex)
					{
						delete wage;
						throw ex;
					}

					//if the sin is not validated, then throw another exception
					if (!activeEmp.luhnsAlgorithm(emp[i].id))
					{
						delete wage;
						throw std::string("");
					}

					//add the validated wage object to the list
					activeEmp += wage;
					delete wage;
				}
			}
		}

		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		
		// TODO: Add your code here to build a list of employees
		//         using smart pointers
		for (size_t i = 0; i < emp.size(); i++)
		{
			for (size_t j = 0; j < sal.size(); j++)
			{
				//if both of ids are equal
				if (emp[i].id == sal[j].id)
				{
					//make a unique_ptr which encloses an EmployeeWage object
					std::unique_ptr<EmployeeWage> wage( new EmployeeWage(emp[i].name, sal[j].salary));
					wage->rangeValidator();

					//if the sin is not validated, then throw another exception
					if (!activeEmp.luhnsAlgorithm(emp[i].id))
						throw std::string("");

					//add the validated wage object to the list
					activeEmp += std::move(wage);
				}
			}
		}

		return activeEmp;
	}
}