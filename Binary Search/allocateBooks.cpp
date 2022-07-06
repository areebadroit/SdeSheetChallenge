bool isAllocationPossible(vector<int> &books, int minimalPages, int students){
    int allotedStudentCount = 1;//No of student already been  allocated any book
    int pagesAllocated = 0;
    for(int i=0;i<books.size();i++){
        if(pagesAllocated+books[i]>minimalPages){
            allotedStudentCount++;
            if(books[i]>minimalPages) return false;
            pagesAllocated = books[i];
        }else{
            pagesAllocated += books[i];
        }
    }
    if(allotedStudentCount <= students) return true;
    return false;
}
int Solution::books(vector<int> &books, int NoOfStudents) {
    //since only one book can be allocate to only one student, if no of student > no of books we return -1
    if(NoOfStudents > books.size()) return -1;
    int low = books[0];
    int high = 0;
    int res = -1;
    //in our seach space initially high will be the tottal  no of pages, i.e., sum of pages of all the books
    for(int i=0;i<books.size();i++){
        high+=books[i];
        low = min(low,books[i]);
    }
    while(low<=high){
        int mid = (low+high) >> 1;//mid is the no of minimal of maximum no od pages alloted to any student
        if(isAllocationPossible(books,mid,NoOfStudents)){
            res = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return res;
}
