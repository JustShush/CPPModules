#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"

int	main(void) {

	{
		/* AAnimal test; */

		const AAnimal*	j = new Dog();
		const AAnimal*	i = new Cat();

		std::cout << i->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		delete(i);
		delete(j);
	}
	{
		AAnimal *arr[10];
		for (int i = 0; i < 10; i++)
		{
			if (i < 5)
				arr[i] = new Dog;
			else
				arr[i] = new Cat;
		}
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			delete(arr[i]);
	}

	//Shallow Copy only copies the pointer. Meaning that, if the original is changed,
	//	the copied object will also change.
	//Deep Copy allocates memory for the copy an then copies the actual values. Copy
	//	is allocated separately from the original.
	std::cout << YELLOW << "\nDeep Copy Test\n" << RESET <<std::endl;
	{
		Dog _Dog;
		Brain *_Brain;
		_Brain = _Dog.getBrain();
		_Brain->setIdeas('a');
		_Brain->printIdea("_Dog");

		Dog _Copy(_Dog);
		Brain *CopyBrain;
		CopyBrain = _Copy.getBrain();
		CopyBrain->printIdea("_Copy");

		_Brain->setIdeas('0');
		std::cout << YELLOW << "IDEAS WERE CHANGED" << RESET << std::endl;
		_Brain->printIdea("_Dog");
		CopyBrain->printIdea("_Copy");
	}
	std::cout << YELLOW << "\nDeep Copy Assingment Op Test\n" << RESET <<std::endl;
	{
		Dog _Dog;
		Brain *_Brain;
		_Brain = _Dog.getBrain();
		_Brain->setIdeas('a');
		_Brain->printIdea("_Dog");

		Dog _Copy = _Dog;
		Brain *CopyBrain;
		CopyBrain = _Copy.getBrain();
		CopyBrain->printIdea("_Copy");

		_Brain->setIdeas('0');
		std::cout << YELLOW << "IDEAS WERE CHANGED\n" << RESET << std::endl;
		_Brain->printIdea("_Dog");
		CopyBrain->printIdea("_Copy");
	}
	std::cout << YELLOW <<  "\nWrongAnimal test\n" << RESET << std::endl;
	{
		Dog Terrier;
		AAnimal *i = &Terrier;
		std::cout << "Terrier is of type: " << i->getType() << std::endl;
		std::cout << "Terrier ";
		i->makeSound();

		const WrongAnimal *OrangeCat = new WrongCat();
		std::cout << "OrangeCat is of type: " << OrangeCat->getType() << std::endl;
		OrangeCat->makeSound();

		WrongCat SiameseCat;
		WrongAnimal *f = &SiameseCat;
		std::cout << "SiameseCat is of type: " << f->getType() << std::endl;
		f->makeSound();

		delete(OrangeCat);
	}
	std::cout << YELLOW <<  "\nCopy and Copy Assignment Op. Test\n" << RESET << std::endl;
	{
		Dog Terrier;
		Terrier.setType("Terrier");
		std::cout << "Terrier Type: " << Terrier.getType() << std::endl;

		Dog Yorkshire(Terrier);
		Dog Scottish = Terrier;
		std::cout << "Yorkshire Type: " << Yorkshire.getType() << std::endl;
		std::cout << "Scottish Type: " << Scottish.getType() << std::endl;
	}

	return (0);
}