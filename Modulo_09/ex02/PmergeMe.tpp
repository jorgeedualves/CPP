
#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"

//função que verifica se um container está ordenada em ordem ascendente.
template <class Sequence>
static bool isSortedAscending(const Sequence &container)
{
    typename Sequence::const_iterator current, next;

    for (current = container.begin(); current != container.end(); ++current)
    {
        next = current;
        ++next;
        if (next == container.end())
        {
            break;
        }
        if (*next < *current)
        {
            return false;
        }
    }
    return true;
}


template<typename Container>
void printUnsorted(const Container& inputContainer, size_t maxElements = 15)
{
  size_t i = 0;
  
  for (typename Container::const_iterator it = inputContainer.begin(); it != inputContainer.end(); ++it)
  {
    std::cout << *it << " ";
    i++;
    if (i >= maxElements)
    {
      std::cout << "[...]";
      break;
    }
  }
  std::cout << std::endl;
}

template<typename Container>
void printSorted(const Container& orderedContainer, size_t maxElements = 15)
{
    size_t i = 0;
    
    for (typename Container::const_iterator it = orderedContainer.begin(); it != orderedContainer.end(); ++it)
    {
        std::cout << *it << " ";
        i++;
        if (i >= maxElements)
        {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;
}





// função que verifica se um container tem um "straggler", ou seja, um elemento excedente 
template <class Sequence> static bool hasStraggler(Sequence &container)
{
    return (static_cast<bool>(container.size() % 2));
};

//função que recebe um contêiner de pares genéricos e classifica cada par dentro desse contêiner.
template <class PairContainer> static void sortPairs(PairContainer &pairs)
{
  typename PairContainer::iterator it;

  for (it = pairs.begin(); it != pairs.end(); ++it)
  {
    if (it->first > it->second)
    {
      std::swap(it->first, it->second);
    }
  }
};

//função que realiza uma ordenação por inserção com base no valor mais alto do par.
template <class PairSequence>
static void insertionSortByLargestValue(PairSequence &pairs, int size)
{
    if (size <= 1)
    {
        return;
    }

    insertionSortByLargestValue(pairs, size - 1);

    typename PairSequence::value_type lastPair = pairs[size - 1];
    int currentIndex = size - 2;

    while (currentIndex >= 0 && pairs[currentIndex].second > lastPair.second)
    {
        pairs[currentIndex + 1] = pairs[currentIndex];
        currentIndex--;
    }

    pairs[currentIndex + 1] = lastPair;
}


//função que cria uma sequência de números de Jacobsthal com base em uma sequência pendente.
template <class Sequence>
static Sequence createJacobsthalSequence(Sequence &pendingSequence)
{
  int index;
  size_t size;
  size_t jacobsthalIndex;
  Sequence jacobsthalSequence;

  if (pendingSequence.empty())
  {
    return (jacobsthalSequence);
  }
  index = 3;
  size = pendingSequence.size();
  while ((jacobsthalIndex = PmergeMe::jacobsthal(index)) < size)
  {
    jacobsthalSequence.push_back(jacobsthalIndex);
    index++;
  }
  jacobsthalSequence.push_back(size);
  return (jacobsthalSequence);
};

//função que cria uma sequência de índices com base nas sequências de Jacobsthal e pendente.
template <class Sequence>static Sequence createIndexSequence(Sequence &jacobsthalSequence, Sequence &pendingSequence)
{
  Sequence indexSequence(1, 0);
  size_t index = 1;
  size_t lastIndex = 1;
  typename Sequence::iterator it;

  if (pendingSequence.empty())
  {
    return (indexSequence);
  }
  for (it = jacobsthalSequence.begin(); it != jacobsthalSequence.end(); it++)
  {
    index = *it;
    size_t pos = index;
    while (pos > lastIndex) {
      indexSequence.push_back(pos - 1);
      pos--;
    }
    lastIndex = index;
  }
  return (indexSequence);
};

//Função que procura a posição correta para inserir um valor na sequência ordenada.(mainSequence)
template <class SequenceIterator>
static SequenceIterator findPosition(SequenceIterator begin, SequenceIterator end, uint target)
{
  SequenceIterator lowerBound = begin;
  SequenceIterator upperBound = end;

  while (lowerBound < upperBound) {
    SequenceIterator middle = lowerBound + (upperBound - lowerBound) / 2;

    if (*middle < target)
    {
      lowerBound = middle + 1;
    } else
    {
      upperBound = middle;
    }
  }
  return (lowerBound);
}

//Função que preenche uma sequência principal com base em sequências de índices e pendente.
template <class Sequence>
static void fillMainSequence(Sequence &mainSequence, Sequence &indexSequence, Sequence &pendingSequence)
{
  uint targetValue;
  uint addedCount;
  typename Sequence::iterator it;
  typename Sequence::iterator targetPosition;

  addedCount = 0;
  for (it = indexSequence.begin(); it != indexSequence.end(); it++)
  {
    targetValue = pendingSequence.at(*it);
    targetPosition = findPosition(mainSequence.begin(),
                        mainSequence.begin() + *it + 1 + addedCount, targetValue);
    mainSequence.insert(targetPosition, targetValue);
    addedCount++;
  }
};

//função estática que insere um valor solto (straggler) em uma sequência principal.
template <class Sequence>
static void insertStragglerElement(Sequence &mainSequence, uint stragglerValue)
{
  typename Sequence::iterator stragglerPos;

  stragglerPos = findPosition(mainSequence.begin(), mainSequence.end(), stragglerValue);
  mainSequence.insert(stragglerPos, stragglerValue);
};

#endif
