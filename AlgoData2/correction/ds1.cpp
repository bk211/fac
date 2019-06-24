#include <vector>
#include <iterator>
#include <iostream>

template <typename Iterator>
void tp1_swap (Iterator it1, Iterator it2){
  //typename Iterator::value_type tmp=*it1;
  auto tmp=*it1;
  *it1=*it2;
  *it2=tmp;
}
template <typename Iterator>
Iterator tp1_partition(Iterator lo, Iterator hi){
  //typename Iterator::value_type pivot = *hi;
  auto pivot = *(hi-1);
  Iterator i=lo;
  for (Iterator j=lo; j!= hi-1; ++j){
    if (*j < pivot){
      tp1_swap (i,j);
      ++i;
    }
  }
  tp1_swap (i, hi-1);
  return i;
}


template <typename Iterator>
void tp1_sort (Iterator first, Iterator last){
  if (first != last){
        Iterator p = tp1_partition (first, last);
        tp1_sort(first, p);
        tp1_sort(p+1, last);
  }
}



template< class ForwardIt1, class ForwardIt2 >
ForwardIt2 ds1_swap_ranges( ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2 ) {
  while (first1 != last1){
    tp1_swap (first1++, first2 ++);
  }
  return first2;
}

template<class InputIt1, class InputIt2, class OutputIt>
OutputIt ds1_set_intersection(InputIt1 first1, InputIt1 last1,
                          InputIt2 first2, InputIt2 last2,
                          OutputIt d_first) {
  while (first1 != last1 && first2!=last2){
    if(*first1 < *first2)
      first1++;
    else {
      if (!(*first2 < *first1)){
        *d_first = *first1;
	d_first++; first1++;
      }
      first2++;
    }
  }
  return d_first;
}

int main(){
  std::vector <int> w ={12,3,6,89,34,2,11,23, 65, 0};
  std::vector <int> v ={12,5,3,8,1,10,9};
  std::cout<< "Avant swap v puis w "<<std::endl;
  for(int n : v) {
        std::cout << n << " ";
  }
  std::cout <<"\n";

  for(int n : w) {
    std::cout << n << " ";
  }
  std::cout <<"\n";
  ds1_swap_ranges (w.begin(), w.begin()+3, v.begin());
  std::cout<< "Apres swap v puis w "<<std::endl;
  for(int n : v) {
    std::cout << n << " ";
  }
  std::cout <<"\n";
  for(int n : w) {
    std::cout << n << " ";
  }
  std::cout <<"\n";

  tp1_sort(v.begin(), v.end());
  tp1_sort(w.begin(), w.end());
   std::cout<< "Apres sort v puis w "<<std::endl;
  for(int n : v) {
    std::cout << n << " ";
  }
  std::cout <<"\n";
  for(int n : w) {
    std::cout << n << " ";
  }
  std::cout <<"\n";


  std::vector <int> x;
  auto it = x.begin ();
  //x.resize(0);
  ds1_set_intersection (v.begin(), v.end(), w.begin(), w.end(), std::inserter(x, it));
  for(int n : x) {
    std::cout << n << " ";
  }
  std::cout <<"\n";

}
