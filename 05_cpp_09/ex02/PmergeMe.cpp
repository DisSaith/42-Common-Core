/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:32:01 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/12 13:48:54 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ======================== Constructors / Destructor ======================== */

PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe() : _vector(), _deque() {}
PmergeMe::PmergeMe( PmergeMe const& copy ) { (void)copy; }
PmergeMe& PmergeMe::operator=( PmergeMe const& copy ) { (void)copy; return *this; }


/* ======================== Methods ======================== */

void	PmergeMe::checkArguments( char **av )
{
	std::vector<int>::iterator	it;
	double						argument;
	size_t						i = 1;
	size_t						j;

	while ( av[i] != NULL )
	{
		j = 0;
		if ( av[i][j] == '\0' )
				throw std::invalid_argument("empty argument.");
		while( av[i][j] )
		{
			if ( !std::isdigit( av[i][j] ) )
				throw std::invalid_argument("only positive integers are allowed.");
			j++;
		}
		argument = std::atoi( av[i] );
		if ( argument > std::numeric_limits<int>::max() )
				throw std::invalid_argument("one argument is higher than INT_MAX.");
		it = std::find( _vector.begin(), _vector.end(), argument );
		if ( it != _vector.end() )
			throw std::invalid_argument("only unique numbers are allowed.");
		_vector.push_back( argument );
		_deque.push_back( argument );
		i++;
	}
	if ( _vector.empty() || _deque.empty() )
		throw std::invalid_argument("no arguments provided.");

}

void	PmergeMe::sorting()
{
	clock_t	start;
	clock_t	end;
	double	vecTime;
	double	deqTime;

	std::cout << "Before:";
	for ( size_t i = 0 ; i < _vector.size() ; i++ )
		std::cout << " " << _vector[i];
	std::cout << std::endl;

    start = clock();
	fordJohnsonVector( _vector );
    end = clock();
    vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After:";
	for ( size_t i = 0 ; i < _vector.size() ; i++ )
		std::cout << " " << _vector[i];
	std::cout << std::endl;

    start = clock();
	fordJohnsonDeque( _deque );
    end = clock();
    deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process " << _vector.size()
			<< " elements with std::vector : " << vecTime << " us" << std::endl
			<< "Time to process " << _deque.size()
			<< " elements with std::deque : " << deqTime << " us" << std::endl;
}


/* ============================= Jacobsthal ================================== */

// J(0)=0, J(1)=1, J(n) = J(n-1) + 2*J(n-2)
// 0, 1, 1, 3, 5, 11, 21, 43, 85, 171 ...
static size_t	jacobsthal( size_t n )
{
	size_t a = 0;
	size_t b = 1;
	size_t c = 0;

	if ( n == 0 )
		return 0;
	if ( n == 1 )
		return 1;
	for ( size_t i = 2 ; i <= n ; i++ )
	{
		c = b + 2 * a;
		a = b;
		b = c;
	}
	return c;
}

static std::vector<size_t>	buildInsertionOrder( size_t size )
{
	std::vector<size_t>	order;
	std::vector<bool>	inserted( size, false );

	size_t	k = 2;
	while ( order.size() < size )
	{
		size_t	jCurr = 0;
		size_t	jPrev = 0;
		while ( true )
		{
			jCurr = jacobsthal( k );
			jPrev = jacobsthal( k - 1 );
			k++;
			if ( jPrev >= size )
			{
				for ( size_t i = 0; i < size; i++ )
					if ( !inserted[i] ) 
					{ 
						order.push_back(i);
						inserted[i] = true;
					}
				return order;
			}
			size_t hi = (jCurr > size) ? size : jCurr;
			bool hasNew = false;
			for ( size_t i = jPrev; i < hi; i++ )
				if ( !inserted[i] ) 
				{ 
					hasNew = true;
					break; 
				}
			if ( hasNew )
				break;
		}
		size_t hi = (jCurr > size) ? size : jCurr;
		for ( size_t i = hi; i-- > jPrev; )
		{
			if ( !inserted[i] )
			{
				order.push_back( i );
				inserted[i] = true;
			}
		}
	}
	return order;
}


/* ====================== Ford-Johnson — std::vector ========================= */

void	PmergeMe::binaryInsertVector( std::vector<int>& chain,
										int val,
										size_t bound )
{
	size_t lo = 0;
	size_t hi = bound;
	size_t mid;

	while ( lo < hi )
	{
		mid = lo + (hi - lo) / 2;
		if ( chain[mid] < val )
			lo = mid + 1;
		else
			hi = mid;
	}
	chain.insert( chain.begin() + lo, val );
}

void	PmergeMe::fordJohnsonVector( std::vector<int>& seq )
{
	size_t n = seq.size();
	
	if ( n <= 1 )
		return;

	// ── Étape 1 : séparer le straggler si n est impair ──
	bool    hasStraggler = (n % 2 != 0);
	int     straggler    = 0;
	if ( hasStraggler ) 
	{ 
		straggler = seq.back();
		seq.pop_back();
		n--; 
	}

	// ── Étape 2 : former les paires (grand, petit) ──
	std::vector<std::pair<int,int> > pairs;
	for ( size_t i = 0; i < n; i += 2 )
	{
		int a = seq[i], b = seq[i + 1];
		if ( a < b ) 
			std::swap(a, b);   // a = max, b = min
		pairs.push_back( std::make_pair(a, b) );
	}

	// ── Étape 3 : trier récursivement les grands ──
	std::vector<int> largers;
	for ( size_t i = 0; i < pairs.size(); i++ )
		largers.push_back( pairs[i].first );
	fordJohnsonVector( largers );

	// Reconstruire l'ordre des paires selon le tri des grands
	std::vector<std::pair<int,int> > sortedPairs;
	std::vector<bool> used( pairs.size(), false );
	for ( size_t i = 0; i < largers.size(); i++ )
		for ( size_t j = 0; j < pairs.size(); j++ )
			if ( !used[j] && pairs[j].first == largers[i] )
				{ 
					sortedPairs.push_back(pairs[j]);
					used[j] = true; 
					break; 
				}

	// ── Étape 4 : construire main chain et pending ──
	// main chain = b1 (petit du 1er grand) + tous les grands triés
	// pending    = petits des paires 2..n (dans l'ordre de leurs grands triés)
	std::vector<int> mainChain;
	std::vector<int> pending;

	mainChain.push_back( sortedPairs[0].second );       // b1 toujours ≤ a1
	for ( size_t i = 0; i < sortedPairs.size(); i++ )
		mainChain.push_back( sortedPairs[i].first );    // a1, a2, ... an
	for ( size_t i = 1; i < sortedPairs.size(); i++ )
		pending.push_back( sortedPairs[i].second );     // b2, b3, ... bn

	// ── Étape 5 : insérer les pending dans l'ordre Jacobsthal ──
	if ( !pending.empty() )
	{
		std::vector<size_t> order = buildInsertionOrder( pending.size() );
		for ( size_t i = 0; i < order.size(); i++ )
		{
			size_t k = order[i];
			binaryInsertVector( mainChain, pending[k], mainChain.size() );
		}
	}

	// ── Étape 6 : insérer le straggler ──
	if ( hasStraggler )
		binaryInsertVector( mainChain, straggler, mainChain.size() );

	seq = mainChain;
}


/* ======================= Ford-Johnson — std::deque ========================= */

void	PmergeMe::binaryInsertDeque( std::deque<int>& chain, int val, size_t bound )
{
	size_t lo = 0;
	size_t hi = bound;
	size_t mid;

	while ( lo < hi )
	{
		mid = lo + (hi - lo) / 2;
		if ( chain[mid] < val )
			lo = mid + 1;
		else
			hi = mid;
	}
	chain.insert( chain.begin() + lo, val );
}

void	PmergeMe::fordJohnsonDeque( std::deque<int>& seq )
{
	size_t n = seq.size();
	if ( n <= 1 )
		return;

	bool    hasStraggler = (n % 2 != 0);
	int     straggler	 = 0;
	if ( hasStraggler ) 
	{ 
		straggler = seq.back(); 
		seq.pop_back();
		n--; 
	}

	std::deque<std::pair<int,int> > pairs;
	for ( size_t i = 0; i < n; i += 2 )
	{
		int a = seq[i], b = seq[i + 1];
		if ( a < b ) 
			std::swap(a, b);
		pairs.push_back( std::make_pair(a, b) );
	}

	std::deque<int> largers;
	for ( size_t i = 0; i < pairs.size(); i++ )
		largers.push_back( pairs[i].first );
	fordJohnsonDeque( largers );

	std::deque<std::pair<int,int> > sortedPairs;
	std::deque<bool> used( pairs.size(), false );
	for ( size_t i = 0; i < largers.size(); i++ )
		for ( size_t j = 0; j < pairs.size(); j++ )
			if ( !used[j] && pairs[j].first == largers[i] )
				{ 
					sortedPairs.push_back(pairs[j]); 
					used[j] = true; 
					break; 
				}

	std::deque<int> mainChain;
	std::deque<int> pending;

	mainChain.push_back( sortedPairs[0].second );
	for ( size_t i = 0; i < sortedPairs.size(); i++ )
		mainChain.push_back( sortedPairs[i].first );
	for ( size_t i = 1; i < sortedPairs.size(); i++ )
		pending.push_back( sortedPairs[i].second );

	if ( !pending.empty() )
	{
		std::vector<size_t> order = buildInsertionOrder( pending.size() );
		for ( size_t i = 0; i < order.size(); i++ )
		{
			size_t k = order[i];
			binaryInsertDeque( mainChain, pending[k], mainChain.size() );
		}
	}

	if ( hasStraggler )
		binaryInsertDeque( mainChain, straggler, mainChain.size() );

	seq = mainChain;
}
