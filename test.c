int	main()
{
	int	a, b;

	a = b = 8;
	a = 1 >> a ;
	printf("%d\n", a);
	a = 1 >> a ;
	printf("%d\n", a);
	a = 1 >> a ;
	printf("%d\n", a);
	return (0);
}
