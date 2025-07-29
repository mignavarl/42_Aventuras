#ifndef _COLORS
# define _COLORS

# define BLACK   "\033[1;30m"
# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN    "\033[1;36m"
# define WHITE   "\033[1;37m"
# define NC      "\033[0m"

#endif // !_COLORS

// Fixed declaration --------------------------------------------------------

#ifndef _FIXED_HPP
# define _FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {
private:
	int value;
	static const int bits = 8;
public:
	Fixed(void);
	Fixed(const int nbr);
	Fixed(const float nbr);
	Fixed(Fixed const& other);
	~Fixed(void);

	Fixed&	operator=(Fixed const& other);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	bool	operator>(Fixed fixed)const;
	bool	operator<(Fixed fixed)const;
	bool	operator>=(Fixed fixed)const;
	bool	operator<=(Fixed fixed)const;
	bool	operator==(Fixed fixed)const;
	bool	operator!=(Fixed fixed)const;

	float	operator+(Fixed fixed)const;
	float	operator-(Fixed fixed)const;
	float	operator*(Fixed fixed)const;
	float	operator/(Fixed fixed)const;

	Fixed	operator++();
	Fixed	operator--();

	Fixed	operator++(int fixed);
	Fixed	operator--(int fixed);

	static	Fixed &min(Fixed &first, Fixed &second);
	static	const Fixed &min(Fixed const &first, Fixed const &second);
	static	Fixed &max(Fixed &first, Fixed &second);
	static	const Fixed &max(Fixed const &first, Fixed const &second);
};
std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif // !_FIXED_HPP
