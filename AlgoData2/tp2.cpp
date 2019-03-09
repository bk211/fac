#include <vector>
#include <iostream>
/*CAI Chaolei
*/
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
	while (first1 != last1 || first2 != last2){		
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
			if(*first1 < *first2){
				*output = *first1;
				++first1;	
				++output;
			}
		
			else {
				*output = *first2;
				++first2;
				++output;
			}		
		}
	}

	return output;

}

template <class InputIterator1, class InputIterator2>
bool includes ( InputIterator1 first1, InputIterator1 last1,
                  InputIterator2 first2, InputIterator2 last2 ){
	while(first2 != last2){
		if(first1 == last1) 
			return false;
		else if(*first1 > *first2)
			return false;
		else if(*first1 == *first2)
			++first2;
		++first1;
	}

	return true;

}

int main(){
	using namespace std;
  	vector <int> v1 ={1,5,6,9,11,13};
  	vector <int> v2 ={1,2,3,5,6,8};
  	vector <int> v3;
  	vector <int> v4= {1,2,3,9,11};
  	cout << "find 11 in v1"<<endl;
  	cout <<*find(v1.begin(),v1.end(),11)<< endl;

  	for(int n : v1) {
        std::cout << n << " ";
    }
  	cout <<endl<<"replace in v1"<<endl;


  	replace(v1.begin(), v1.end(), 5, 4);
  	replace(v1.begin(), v1.end(), 13, 69);
  
  	for(int n : v1) {
        std::cout << n << " ";
  	}

  	cout <<endl;
	v3.resize(20);
  	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());

  	cout << "merge v1 v2 in v3:"<< endl;
  	for(int n : v3) {
        std::cout << n << " ";
  	}

  	cout <<endl<<"v4 in v3?"<<endl;
  	cout <<includes(v3.begin(),v3.end(),v4.begin(),v4.end())<<endl;
  	return 0;
}
