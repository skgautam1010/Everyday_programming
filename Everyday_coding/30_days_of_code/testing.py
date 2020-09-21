
class TestDataEmptyArray(object):
    
    @staticmethod
    def get_array():
        list1=[]
        return list1

class TestDataUniqueValues(object):

    @staticmethod
    def get_array():
        list2=[5,3,2,7]
        return list2
    @staticmethod
    def get_expected_result():
        return 2



class TestDataExactlyTwoDifferentMinimums(object):

    @staticmethod
    def get_array():
        list3=[1,3,1]
        return list3

    @staticmethod
    def get_expected_result():
        return 0

