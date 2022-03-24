/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:37:02 by asfaihi           #+#    #+#             */
/*   Updated: 2022/03/24 10:30:32 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "../vector/vector.hpp"

namespace ft
{
	template < class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T								value_type;
			typedef Container						container_type;
			typedef typename Container::size_type	size_type;

		protected:
			Container	c;

		public:
			explicit stack(const container_type &ctnr = container_type()) : c(ctnr) {};
			bool				empty() const { return c.empty(); };
			size_type			size() const { return c.size(); };
			value_type			&top() { return c.back(); };
			const value_type	&top() const { return c.back(); };
			void				push(const value_type &val) { c.push_back(val); };
			void				pop() { c.pop_back(); };

			template <class T1, class Container1>
			friend bool operator==(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);

			template <class T1, class Container1>
			friend bool operator!=(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);

			template <class T1, class Container1>
			friend bool operator<(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);

			template <class T1, class Container1>
			friend bool operator<=(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);

			template <class T1, class Container1>
			friend bool operator>(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);

			template <class T1, class Container1>
			friend bool operator>=(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);
	};
	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c == rhs.c); };

	template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c != rhs.c); };

	template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c < rhs.c); };

	template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c <= rhs.c); };

	template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c > rhs.c); };

	template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c >= rhs.c); };
}

#endif