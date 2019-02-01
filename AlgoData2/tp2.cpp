#include <vector>
#include <iostream>

template< class InputIt, class T>
InputIt find( InputIt first, InputIt last, const T& value){
	while(first != last){
		if (*first == value)
			return first;
		++first;
	}
	return last;

}


template < class ForwardIt, class T>
void replace (ForwardIt first, ForwardIt last, const T& old_value,
	const T& new_value)
{
	while(first != last){
		if (*first == old_value)
			*first = new_value;
	
		++first;
	}
}

template < class InputIt , class OutputIt>
OutputIt merge(InputIt first1, InputIt last1,
		 InputIt first2, InputIt last2, 
		 OutputIt output)
{
//	InputIt output;
	std::cout<<"begin fct"<<std::endl;
	while (first1 != last1 && first2 != last2){
		//std::cout<<"bk1"<<std::endl;
		
		if(first1 ==last1){
			*output = *first2;
			++first1;
			++output;
		}
		
		else if(first2 == last2){
			*output = *first1;
			++first1;	
			++output;
		}
		else{
			//std::cout<<"bk2"<<std::endl;
		
			if(*first1 < *first2){
				*output = *first1;
				++first1;	
				++output;
			}
		
			else{
				std::cout<<"bk3"<<std::endl;
				*output = *first2;
		
				std::cout<<"bk5"<<std::endl;
				++first2;
				++output;
			}
		std::cout<<"bk4"<<std::endl;
		
		}
	}

	return output;

}


//merge
// includes
int main(){
	using namespace std;
  	vector <int> v1 ={12,5,3,8,1,10,9,5,5};
  	vector <int> v2 ={12,3,6,89,34,2,11,23};
  	vector <int> v3;
  	cout <<"begin\n";
  	/*for(int n : v) {
        std::cout << n << " ";
  	}*/

  	//replace(v.begin(), v.end(), 5, 99);
  	//replace(v.begin(), v.end(), 50, 99);
  
  	/*cout << "after "<< endl;
    for(int n : v) {
        std::cout << n << " ";
  	}*/
	//cout << *find(v.begin(),v.end(),11)<< endl;
	cout << "before "<< endl;
  	/*for(int n : v3) {
        std::cout << n << " ";
  	}
	*/

  	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
/*
  	cout << "after "<< endl;
  	for(int n : v3) {
        std::cout << n << " ";
  	}
	*/

  	cout <<endl<<"end\n";
  	return 0;
}
