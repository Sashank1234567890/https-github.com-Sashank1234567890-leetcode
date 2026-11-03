class Solution:
    def minMovesToSeat(self, seats: list[int], students: list[int]) -> int:
        seats.sort()
        students.sort()
        return sum(list(map(lambda x,y: abs(x-y),seats,students)))
        