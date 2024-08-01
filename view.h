#ifndef VIEW_H	
#define VIEW_H

#include "types.h" //contains user defined data types

//structure is used to store information required for storing the various MP3 Tag details
//information about output data is allso stored

typedef struct _TagInfo
{
	/*source mp3 file info*/
	FILE* fptr_mp3;
    char frame_Id [4];

    /* Title Info */
    char* title_tag;
    uint title_tag_size;

    /* Artist Info */
    char* artist_tag;
    uint artist_tag_size;

    /* Album Info */
    char* album_tag;
    uint album_tag_size;

    /* Year of Release Info */
    char* year;
    uint year_size;

    /* Content Type Info */
    char* content_type;
    uint content_type_size;

    /* Comments Info */
    char* comments;
    uint comment_size;

} TagInfo;


/*printing the mp3 tag details function prototype*/

/*check operation type*/
OperationType check_operation(char *argv[]);

/*perform validation of the arguments passed and store in the structure*/
Status read_and_validate_mp3_file(char *argv[], TagInfo *mp3tagInfo);

/*perform the viewing tag details operation*/
Status view_tag(char *argv[],TagInfo *mp3tagInfo);

/* Common function to display the various Frame contents of the MP3 file */
Status get_and_display_data (const char* str_frame, const char* str_Id, char* frame_Id, uint* tag_size, char* tag, FILE* fptr);

#endif
