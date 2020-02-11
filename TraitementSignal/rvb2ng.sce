function [result] = rvb2ng(image)
    disp("start rvg2ng")
    dr = 0.299
    dv = 0.587
    db = 0.114
    result =imlincomb(dr,image)

endfunction
