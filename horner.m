function [px] = horner(a,x)
%HORNER Function that computes a polynomial expression using Horner's Algo
    n = length(a)-1;
    px=a(1);
    for i=2:n+1
        px=x*px+a(i);
    end
end

