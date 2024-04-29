#include <vector>

int bsearch(std::vector<int> const & n, int v)
{
	int l = 0;
	int r = n.size() - 1;
	while (l <= r) {
		int m = (int)(((long long)l + (long long)r) / 2);
		if (n[m] < v)
			l = m + 1;
		else if (n[m] > v)
			r = m - 1;
		else
			return m;
	}
	return -1;
}

int bsearchl(std::vector<int> const & n, int v)
{
	int l = 0;
	int r = n.size();
	while (l < r) {
		int m = (int)(((long long)l + (long long)r) / 2);
		if (n[m] < v)
			l = m + 1;
		else
			r = m;
	}
	return l;
}

int bsearchr(std::vector<int> const & n, int v)
{
	int l = 0;
	int r = n.size();
	while (l < r) {
		int m = (int)(((long long)l + (long long)r) / 2);
		if (n[m] > v)
			r = m;
		else
			l = m + 1;
	}
	return r - 1;
}