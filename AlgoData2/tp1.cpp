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
  std::cout<<pivot<<std::endl;
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

int main(){
  //std::vector <int> v ={12,3,6,89,34,2,11,23};
  std::vector <int> v ={12,5,3,8,1,10,9};
  tp1_sort(v.begin(),v.end());
  for(int n : v) {
        std::cout << n << " ";
  }
  std::cout <<"\n";
}

