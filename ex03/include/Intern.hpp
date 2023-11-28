#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include <map>

class AForm;

class Intern {
	private:
		typedef AForm *(*FormFactory)(std::string const &);
		std::map<std::string, FormFactory> formMap;
	public:
		Intern();
		Intern(Intern const & src);
		~Intern();
		Intern & operator=(Intern const & src);

		AForm * makeForm(std::string const & formName, std::string const & target) const;
};

#endif