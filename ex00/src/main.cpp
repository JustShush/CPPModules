#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"

int	main(void) {

	std::cout << YELLOW <<  "\nSubject test\n" << RESET << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << i->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete(meta);
		delete(i);
		delete(j);
	}
	std::cout << YELLOW <<  "\nWrongAnimal test\n" << RESET << std::endl;
	{
		Dog Terrier;
		Animal *k = &Terrier;
		std::cout << "Terrier is of type: " << k->getType() << std::endl;
		std::cout << "Terrier ";
		k->makeSound();

		const WrongAnimal *OrangeCat = new WrongCat();
		std::cout << "OrangeCat is of type: " << OrangeCat->getType() << std::endl;
		OrangeCat->makeSound();

		WrongCat SiameseCat;
		WrongAnimal *f = &SiameseCat;
		std::cout << "SiameseCat is of type: " << f->getType() << std::endl;
		f->makeSound();

		delete(OrangeCat);
	}
	std::cout << YELLOW <<  "\nCopy and Copy Assignment Test\n" << RESET << std::endl;
	{
		Dog Terrier;
		Terrier.setType("Terrier");
		std::cout << "Terrier Type: " << Terrier.getType() << std::endl;

		Dog Yorkshire(Terrier);
		Dog JackRussell = Terrier;
		std::cout << "Yorkshire Type: " << Yorkshire.getType() << std::endl;
		std::cout << "JackRussell Type: " << JackRussell.getType() << std::endl;
	}

	return (0);
}