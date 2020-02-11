image = imread("img/barbara.png");
filtre = 1/9 * ones(3,3);
resultat = zeros(size(image,1), size(image,2));

for i = 1 : 20
    disp(i)
    for j = 1: 10
        disp(j)
    end
end

imshow(resultat)
