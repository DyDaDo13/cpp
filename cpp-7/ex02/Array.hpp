/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:40:51 by dydado13          #+#    #+#             */
/*   Updated: 2024/05/09 16:47:11 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP_
# define ARRAY_HPP_

template< typename T>
class Array
{
	public:
		Array(): _size(0) {
			std::cout << "Default Constructor called: created empty Array of size 0" << std::endl;
			this->_array = new T[this->_size];
			// for (unsigned int i = 0; i < this->size(); i++)
				// std::cout << this->_array << std::endl;
		}

		Array(unsigned int size): _size(size) {
			std::cout << "Constructor for an Array of size " << size << " called" << std::endl;
			this->_array = new T[this->_size];
			// for (unsigned int i = 0; i < this->size(); i++)
				// std::cout << this->_array[i] << std::endl;
		}

		Array(const Array &cpy): _size(cpy.size()) {
			std::cout << "Copy Constuctor called" << std::endl;
			this->_array = NULL;
			*this = cpy;
		}

		Array &operator=(const Array &n) {
			if (this->_array != NULL)
				delete [] this->_array;
			if (n.size() != 0) {
				this->_size = n.size();
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->size(); i++)
					this->_array[i] = n._array[i];
			}
			return (*this);
		}
		
		T &operator[]( unsigned int index ) {
			if (index >= this->_size || this->_array == NULL) {
				std::cout << "index: " << index << std::endl;
				throw Array<T>::InvalidIndexException();
			}
			return (this->_array[index]);
		}
		
		~Array() {
			if (this->_array != NULL)
				delete [] this->_array;
		}

		class	InvalidIndexException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
		
		unsigned int size() const {
			return (this->_size);
		}
		
	private:
		T				*_array;
		unsigned int	_size;
};

template< typename T >
const char	*Array<T>::InvalidIndexException::what() const throw() {
	return ("Error: Invalid index");
}

#endif