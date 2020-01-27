foo=(imread('img/peppers256.png'));
maxi = max(foo)
mini = min(foo)
disp(maxi)
disp(mini)


for i = 1:256,
    for j = 1:256,
        if foo(i,j) > 120 then
            foo(i,j) = 256;
        else
            foo(i,j) = 0;
        end,
    end,
end;

