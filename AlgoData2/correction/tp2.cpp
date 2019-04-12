#include <vector>
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

template <class InputIt, class T>
InputIt tp2_find (InputIt first, InputIt last, const T& value){
  for (; first != last; ++first) {
    if (*first==value){
      return first;
    }
  }
  return first;
}
template<class ForwardIt, class T>
void tp2_replace(ForwardIt first, ForwardIt last,
             const T& old_value, const T& new_value)
{
    for (; first != last; ++first) {
        if (*first == old_value) {
            *first = new_value;
        }
    }
}


template<class InputIt1, class InputIt2, class OutputIt>
OutputIt tp2_merge(InputIt1 first1, InputIt1 last1,
               InputIt2 first2, InputIt2 last2,
               OutputIt d_first) {
  for (; first1 != last1; ++d_first) {
    if (first2 == last2) {
       while (first1 != last1){
          *d_first++ = *first1++;
       }
       return d_first;
     }
     if (*first2 < *first1) {
       *d_first = *first2;
       ++first2;
     } else {
       *d_first = *first1;
       ++first1;
     }
  }
  while (first2 != last2){
    *d_first++ = *first2++;
  }
  return d_first;
}

template<class InputIt1, class InputIt2>
bool tp2_includes(InputIt1 first1, InputIt1 last1,
              InputIt2 first2, InputIt2 last2)
{
  while (first2!=last2) {
    if ( (first1==last1) || (*first2<*first1) ) return false;
    if (!(*first1<*first2)) ++first2;
    ++first1;
  }
  return true;
}

int main(){
  std::vector <int> w ={12,3,6,89,34,2,11,23, 65, 0};
  std::vector <int> v ={12,5,3,8,1,10,9};
  for(int n : v) {
        std::cout << n << " ";
  }
 std::cout <<"\n";
 auto it = tp2_find(v.begin(),v.end(), 8);
 if (it != v.end()) 
   std::cout<<*it<<std::endl;
 else
   std::cout<<"Element absent de l'ensemble"<<std::endl;

 replace (v.begin(), v.end(), 5, 4);
 for(int n : v) {
        std::cout << n << " ";
  }
 std::cout <<"\n";
 tp1_sort (w.begin(), w.end());
 tp1_sort(v.begin(), v.end());
 std::vector <int> x;
 x.resize(v.size()+w.size());
 tp2_merge (v.begin(), v.end(), w.begin(), w.end(), x.begin());
 for(int n : x) {
        std::cout << n << " ";
  }
 std::cout <<"\n";
 std::cout <<tp2_includes(v.begin(), v.end(), w.begin(), w.end())<<std::endl;

}


