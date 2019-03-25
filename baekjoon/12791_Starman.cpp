#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	map<int, string> album;
	album[1967] = "DavidBowie";
	album[1969] = "SpaceOddity";
	album[1970] = "TheManWhoSoldTheWorld";
	album[1971] = "HunkyDory";
	album[1972] = "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars";
	album[1973] = "AladdinSane\n1973 PinUps";
	album[1974] = "DiamondDogs";
	album[1975] = "YoungAmericans";
	album[1976] = "StationToStation";
	album[1977] = "Low\n1977 Heroes";
	album[1979] = "Lodger";
	album[1980] = "ScaryMonstersAndSuperCreeps";
	album[1983] = "LetsDance";
	album[1984] = "Tonight";
	album[1987] = "NeverLetMeDown";
	album[1993] = "BlackTieWhiteNoise";
	album[1995] = "1.Outside";
	album[1997] = "Earthling";
	album[1999] = "Hours";
	album[2002] = "Heathen";
	album[2003] = "Reality";
	album[2013] = "TheNextDay";
	album[2016] = "BlackStar";
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, sum = 0;
		cin >> a >> b;
		for (auto x : album)
		{
			if (a <= x.first && b >= x.first)
			{
				sum++;
				if (x.first == 1973 || x.first == 1977) sum++;
			}
		}
		cout << sum << "\n";
		for (auto x : album)
		{
			if (a <= x.first && b >= x.first)
				cout << x.first << " " << x.second + "\n";
		}
	}
}