#include "../inc/Span.hpp"

int main() {
	{
		Span sp = Span(5);

		// Subject Test
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span span(5);
		// Test 1: Normal Case
		span.addNumber(1);
		span.addNumber(3);
		span.addNumber(6);
		span.addNumber(9);
		span.addNumber(15);
		std::cout << "Test 1 - Normal Case:" << std::endl;
		std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;	// Expected: 2
		std::cout << "Longest Span: " << span.longestSpan() << std::endl;	// Expected: 14
		std::cout << std::endl;
	}
	{
		Span span(4);
		// Test 2: All Elements are the Same
		span.addNumber(5);
		span.addNumber(5);
		span.addNumber(5);
		span.addNumber(5);
		std::cout << "Test 2 - All Elements are the Same:" << std::endl;
		std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;	// Expected: 0
		std::cout << "Longest Span: " << span.longestSpan() << std::endl;	// Expected: 0
		std::cout << std::endl;
	}
	{
		Span span(5);
		// Test 3: Negative and Positive Numbers
		span.addNumber(-10);
		span.addNumber(-5);
		span.addNumber(0);
		span.addNumber(5);
		span.addNumber(10);
		std::cout << "Test 3 - Negative and Positive Numbers:" << std::endl;
		std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;	// Expected: 5
		std::cout << "Longest Span: " << span.longestSpan() << std::endl;	// Expected: 20
		std::cout << std::endl;
	}
	{
		Span span(2);
		// Test 4: Only Two Elements
		span.addNumber(1);
		span.addNumber(100);
		std::cout << "Test 4 - Only Two Elements:" << std::endl;
		std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;	// Expected: 99
		std::cout << "Longest Span: " << span.longestSpan() << std::endl;	// Expected: 99
		std::cout << std::endl;
	}
	{
		Span span(1);
		// Test 5: Single Element (Error Case)
		span.addNumber(42);
		std::cout << "Test 5 - Single Element (Error Case):" << std::endl;
		std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;	// Expected: -1 (Error)
		std::cout << "Longest Span: " << span.longestSpan() << std::endl;	// Expected: -1 (Error)
		std::cout << std::endl;
	}
	{
		Span span(1);
		// Test 6: Empty Vector (Error Case)
		std::vector<int> tmp = span.getArray();
		tmp.clear();
		std::cout << "Test 6 - Empty Vector (Error Case):" << std::endl;
		std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;	// Expected: -1 (Error)
		std::cout << "Longest Span: " << span.longestSpan() << std::endl;	// Expected: -1 (Error)
		std::cout << std::endl;
	}

	return 0;
}