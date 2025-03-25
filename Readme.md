# Range query Data Structure
### Common usecases : Min/Max/Sum in a range

## Segment tree
- Segment tree devides the entire range(root node) into subranges(each of equal size) and stores the result as node values
- Result is calculated in a bottom up fashion starting from indivisable ranges
- Results are stored in an array where each index represents level order position(assuming complete tree) of the node(a given range)

### build(idx, low, high) Time O(n)
- Use left and right population at each level
 
![image](https://github.com/user-attachments/assets/8d927232-bffe-4b5f-b37a-ad1568755445)

### query(idx, low, high, rangeLow, rangeHigh) Time O(log n)
- No overlap : Don't use the result 
- Partial overlap : Use left and right results
- Complete overlap : Use the result as it is

### update(idx, low, high, id, val) Time O(log n)
- Update required index and following nodes going upwards	
