#include "../test_utility.cpp"

int	main ()
{
	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;

	std::vector<int> orig_1(1);
	ft::vector<int> my_1(1);
	init_vector_all(&orig_1, &my_1);

	std::vector<int> orig_2(SIZE_100);
	ft::vector<int> my_2(SIZE_100);
	init_vector_all(&orig_2, &my_2);

	std::vector<int> orig_3(SIZE_10);
	ft::vector<int> my_3(SIZE_10);
	init_vector_all(&orig_3, &my_3);

	//=============================================================
	std::cout << "erase(begin()) size=1 (use 1)" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.erase(orig_1.begin());
	temp_orig += vektor_base_test(&orig_1);
	time_orig = clock() - time_orig;

	time_my = clock();
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	my_1.erase(my_1.begin());
	temp_my += vektor_base_test(&my_1);
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "erase(begin()) size=100 (use 100)" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_2);
	for (size_t i = 0; i < SIZE_100; i++)
		orig_2.erase(orig_2.begin());
	temp_orig += vektor_base_test(&orig_2);
	time_orig = clock() - time_orig;

	time_my = clock();
	//действия c собственной копией
	temp_my += vektor_base_test(&my_2);
	for (size_t i = 0; i < SIZE_100; i++)
		my_2.erase(my_2.begin());
	temp_my += vektor_base_test(&my_2);
	//temp_my += " ";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "start size = 10\nerase(begin() + 1)" << std::endl;
	std::cout << "erase(begin() + 3)" << std::endl;
	std::cout << "erase(begin() + 5)" << std::endl;
	std::cout << "erase(begin() + 6)" << std::endl;
	std::cout << "erase(begin() + 5)" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_3);

	orig_3.erase(orig_3.begin() + 1);
	orig_3.erase(orig_3.begin() + 3);
	orig_3.erase(orig_3.begin() + 5);
	orig_3.erase(orig_3.begin() + 6);
	orig_3.erase(orig_3.begin() + 5);

	temp_orig += vektor_base_test(&orig_3);
	time_orig = clock() - time_orig;

	time_my = clock();
	//действия c собственной копией
	temp_my += vektor_base_test(&my_3);

	my_3.erase(my_3.begin() + 1);
	my_3.erase(my_3.begin() + 3);
	my_3.erase(my_3.begin() + 5);
	my_3.erase(my_3.begin() + 6);
	my_3.erase(my_3.begin() + 5);

	temp_my += vektor_base_test(&my_3);
	//temp_my += " ";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================

	return (!rez);
}
