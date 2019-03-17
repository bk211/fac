template<typename T>
const  T & Max (T&A, T&B){
	return A<B? B:A;
}

auto Max2 = [](auto A,auto B){
	return A<B? B:A;
}


int main()
{
	int x =3;
	iny y = 4;
	int z = Max(x,y);
	return 0;
}

