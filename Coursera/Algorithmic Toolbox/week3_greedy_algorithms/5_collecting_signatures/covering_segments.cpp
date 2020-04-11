#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};
bool compareInterval(Segment i1, Segment i2) 
{ 
    if(i1.start==i2.start)
      return i1.end<i2.end;
    return (i1.start < i2.start); 
} 
vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  sort(segments.begin(),segments.end(),compareInterval);
  int start_=segments[0].start,end_=segments[0].end;
  for (size_t i = 0; i < segments.size(); i++)
  {
    //int temp=segments[i].start;
    if(segments[i].start<=end_)
    {
      start_=segments[i].start;
      if(end_>segments[i].end)
        end_=segments[i].end;
    }
    else {
      points.push_back(start_);
      start_=segments[i].start,end_=segments[i].end;
    }
  }
  points.push_back(start_);
  /*for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }*/
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
