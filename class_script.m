%1
% a.
% p(x) = 3x^4 + 7x^3 - x^2 - 4x - 4
% <=> ((((3x+7)x-1)x-4)x-4)
% Successively factoring

% b.
% this might be reorganized so it only involves 4 multiplications and 4
% additions thus the amount of multiplications is the degree of the
% polynomial

% pn(x) = (((a1x + a2)x+a3)x...)x+an)x-an+1

% c.
function [px] = horner(a,x)
%HORNER Function that computes a polynomial expression using Horner's Algo
 n = length(a)-1;
 px=a(1); % acessing the array is super weird
 for i=2:n+1 % ew no parenthesis
  px=x*px+a(i); 
 end
end
% e
% polyval

%2
% a use the horner function in order top find the decimal representation of
% the numbers 1000 and 110101011, (that is binary to decimal)

% To solve this we need only to represent these numbers in an array
% containing the sequence of bits using the regular algorithm to convert
% decimal to binary which is in itself a polynomial
% THUS this exercise is trivial.

% b
% bin2dec hex2dec base2dec

%3
% a

function bits = intdectobin(N)
rever
end

