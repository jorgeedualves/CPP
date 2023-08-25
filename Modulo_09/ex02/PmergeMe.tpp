
#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"

template <class Seq> static bool isSorted(Seq &container)
{
    typename Seq::iterator it, next;

    for (it = container.begin(); it != container.end(); it++)
    {
      next = it + 1;
      if (next == container.end())
      {
        break;
      }
      if (*next < *it)
      {
        return (false);
      }
    }
    return (true);
};

template <class Seq> static bool hasStraggler(Seq &container)
{
    return (static_cast<bool>(container.size() % 2));
};

template <class PairSeq> static void sortPairs(PairSeq &container)
{
  typename PairSeq::iterator it;

  for (it = container.begin(); it != container.end(); it++)
  {
    if (it->first > it->second)
    {
      std::swap(it->first, it->second);
    }
  }
};

template <class PairSeq> static void insertionSortByLargestValue(PairSeq &seq, int n)
{
  int i;
  typename PairSeq::value_type lastElement;

  if (n <= 1)
  {
    return;
  }
  insertionSortByLargestValue(seq, n - 1);
  i = n - 2;
  lastElement = seq[n - 1];
  while (i >= 0 && seq[i].second > lastElement.second)
  {
    seq[i + 1] = seq[i];
    i--;
  }
    seq[i + 1] = lastElement;
};

template <class Seq> static Seq createJacobsthalSeq(Seq &pendingSeq)
{
  int idx;
  size_t size;
  size_t jacobsthalIdx;
  Seq jacobsthalSeq;

  if (pendingSeq.empty())
  {
    return (jacobsthalSeq);
  }
  idx = 3;
  size = pendingSeq.size();
  while ((jacobsthalIdx = PmergeMe::jacobsthal(idx)) < size)
  {
    jacobsthalSeq.push_back(jacobsthalIdx);
    idx++;
  }
  jacobsthalSeq.push_back(size);
  return (jacobsthalSeq);
};

template <class Seq> static Seq createIndexSeq(Seq &jacobSeq, Seq &pendingSeq)
{
  Seq indexSeq(1, 0);
  size_t index = 1;
  size_t lastIndex = 1;
  typename Seq::iterator it;

  if (pendingSeq.empty())
  {
    return (indexSeq);
  }
  for (it = jacobSeq.begin(); it != jacobSeq.end(); it++)
  {
    index = *it;
    size_t pos = index;
    while (pos > lastIndex) {
      indexSeq.push_back(pos - 1);
      pos--;
    }
    lastIndex = index;
  }
  return (indexSeq);
};

template <class SeqIt> static SeqIt findPos(SeqIt begin, SeqIt end, uint target)
{
  SeqIt low, high;

  low = begin;
  high = end;
  while (low < high) {
    SeqIt mid = low + (high - low) / 2;

    if (*mid < target)
    {
      low = mid + 1;
    } else
    {
      high = mid;
    }
  }
  return (low);
}

template <class Seq> static void fillMainSeq(Seq &mainSeq, Seq &indexSeq, Seq &pendingSeq)
{
  uint target;
  uint addedCount;
  typename Seq::iterator it;
  typename Seq::iterator targetPos;

  addedCount = 0;
  for (it = indexSeq.begin(); it != indexSeq.end(); it++)
  {
    target = pendingSeq.at(*it);
    targetPos = findPos(mainSeq.begin(),
                        mainSeq.begin() + *it + 1 + addedCount, target);
    mainSeq.insert(targetPos, target);
    addedCount++;
  }
};

template <class Seq>
static void insertStraggler(Seq &mainSeq, uint straggler)
{
  typename Seq::iterator stragglerPos;

  stragglerPos = findPos(mainSeq.begin(), mainSeq.end(), straggler);
  mainSeq.insert(stragglerPos, straggler);
};




#endif
