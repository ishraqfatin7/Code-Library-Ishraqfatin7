Int LongestIncreasingSubsequenceLength(std::vector<int>& v)
{
    if (v.size() == 0) // boundary case
        return 0;
    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
    tail[0] =v[0];
    for (int i = 1; i < v.size(); i++) {
        auto b = tail.begin(), e = tail.begin() + length;
        auto it = lower_bound(b, e, v[i]);
        if (it == tail.begin() + length&&v[i]==tail[length-1].first+1)
            tail[length++] = v[i];
            else *it=v[i];
    }
    return length;
}
