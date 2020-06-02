
function contour(img,filter,thresh)
    res= edge(img, filter,thresh);
    imshow(res);
endfunction
