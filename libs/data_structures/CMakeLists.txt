add_library(data_structures
        bitset/bitset.c
        vector/vector.c
        vector/vectorVoid.c
        matrix/matrix.c
        matrix/matrix_tasks/takes.c
        string_/string_.c
        string_/tasks/tasks_string.c
        )

target_link_libraries ( data_structures algorithms )