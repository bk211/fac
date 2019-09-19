a= 6, b = 7, c = 4
c= (a & b) = 110= 6  6= 110 7=111 

a= true b=5 c= 3
b= (!a ? b*=c :c*=b)
!a = false
si false, alors c *= b
c = 3*5 = 15

a = 5 b=2 c = 4
b = ( (b|c) != ++a? 5:1)
b = 0010 c = 0100
(b|c) =0110 ==6
++a = 6 ,
6 != 6? False
alors b= 1


a= 0 b =1 c =2
a = (a++)* ((++b) * (c++))
0 *
b = 2
2 * 2 = 4
0 * 4 = 0
a=1, b = 2,c = 3

a = 0 b =1 c =2
a = (++a) * ((++b) * (c++))
1* b * c ou b = 2 ,c = 2++
1* 4 = 4
a= 4, b = 2 , c = 3

a= 8, b = true , c = 4
b = (false || ((c*=2)>0))
false ou ( c*=2 > 0?)
c= 4, c*=4 = 8, 8> 0 donc true
donc b = true

a= 8, b = false , c = 4
b = (true || ((c*=2)>0))
b = true

a = 5, b= 4 , c = 3
c = ((a>b) && (b>c)?b:c)
(a>b)? true
(b>c)? true, alors true && b ou b = 4
donc c = true

a= 6, b = false, c= 7
a &= ((true &&b)? -a : c -=3)
autremendit,  a= a & ((true &&b)? -a : c -=3)
a en binaire == 0110
(true && b) == true && false == false
alors c -=3, c = 4 , 4 en binaire vaut 100
a = 0110 & 0100 == 0100
a = 4

a = 4, b = 8, c =1
b+= (a++) + (++c)
autremendit, b = b + ( a++) + (++c)
a vaudra 4 a la fin, c vaut deja 2
b = 8 + 4 + 2= 14
c = 2, a =4
