#include <iostream>

using namespace std;

int CalcPower(int& N, int& M)
{
	int temp = N;
	N = M;
	M = temp;
	
	int a = 3;

	N = a;
	N = M;
	N = a;

	return N;
}

int main()
{
	for (size_t i = 0; i < 10; i++)
	{
		cout << "hi";

		for (size_t i = 0; i < 10; i++)
		{
			for (size_t i = 0; i < 10; i++)
			{
				for (size_t i = 0; i < 10; i++)
				{
					for (size_t i = 0; i < 10; i++)
					{
						for (size_t i = 0; i < 10; i++)
						{
							for (size_t i = 0; i < 10; i++)
							{
								for (size_t i = 0; i < 10; i++)
								{
									for (size_t i = 0; i < 10; i++)
									{
										for (size_t i = 0; i < 10; i++)
										{
											for (size_t i = 0; i < 10; i++)
											{
												for (size_t i = 0; i < 10; i++)
												{
													for (size_t i = 0; i < 10; i++)
													{
														for (size_t i = 0; i < 10; i++)
														{
															for (size_t i = 0; i < 10; i++)
															{
																for (size_t i = 0; i < 10; i++)
																{
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}