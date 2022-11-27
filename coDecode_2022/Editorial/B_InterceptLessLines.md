# <center><u>[B. Intercept-Less Lines](https://www.hackerrank.com/contests/codecode-pec/challenges/intercept-less-lines)</u></center>
---

The problem asks for minimum number of lines passing through origin which covers all points. 

We can make $N$ lines in which each $i^{th}$ line covers only $i^{th}$ point. Since the line must pass through origin so we have two points, **except** when $(x_i, y_i) = (0, 0)$.

Now the only thing left is to unique how many distinct lines exist among these.

**For example:** $x = 2 \cdot y$ and $2 \cdot x = 4 \cdot y$ represent same line.

We can check number of distinct lines by checking number of distinct slopes. 

There will be precision issues if you use `double` to store points or slope. Same precision issue will be in python. Try doing `print(1 == 1 + 1e-16)`. One other mistake participants did was division by $0$.

We tried a lot but couldn't make a case for which `long double` fails due to precision issues.

Instead of storing $(\frac{y}{x})$, we store $(x, y)$ representing denominator and numerator of fraction in it's simplest form respectively. 

Simplest Form of $(2, 4)$ is $(1, 2)$. To make fraction in it's simplest form simply make $x = \frac{x}{gcd(x, y)}$ and $y = \frac{y}{gcd(x, y)}$. 

The only case that is left to handle is $(1, -2)$ and $(-1, 2)$. To handle that we can fix one out of numerator and denominator which will be negative (if one of the two is negative). See Code below for implementation details.

##### [`Intended CPP Code handling fractions`](./../Codes/B_InterceptLessLines_intended.cpp)
##### [`CPP Code using long double`](./../Codes/B_InterceptLessLines_alt.cpp)