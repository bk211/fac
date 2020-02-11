
Image = imread("img/peppers256.png");
Filtre = fspecial("gaussian", [9, 9], 0.2);
Resultat = imfilter(Image, Filtre);
imshow(Resultat);
