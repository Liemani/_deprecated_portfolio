class NoteBook:
    def __init__(self, title):
        self.__title = title
        self.__note_list = []

    def get_number_of_all_pages(self):
        return len(self.__note_list)

    def get_number_of_all_character(self):
        total = 0
        for note in self.__note_list:
            total += note.get_number_of_all_character()

        return total

    def add_note(self, note, index=0):
        if self.__is_in_of_bounds(index - 1):
            self.__note_list.insert(index, note)
        else:
            self.__note_list.append(note)

    def remove_note(self, index):
        if self.__is_in_of_bounds(index - 1):
            del self.__note_list[index - 1]

    def __is_in_of_bounds(self, index):
        return 0 <= index < len(self.__note_list)


class Note:
    def __init__(self, contents):
        self.__contents = contents

    def __str__(self):
        return self.__contents

    def get_number_of_all_character(self):
        return len(self.__contents)

    def remove(self):
        self.__contents = "Deleted note"
