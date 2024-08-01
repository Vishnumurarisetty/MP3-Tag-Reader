#include <stdio.h>
#include "types.h"
#include "view.h"
#include "edit.h"

int main(int argc, char *argv[])
{
	TagInfo mp3tagInfo;
	TagData mp3tagData;

	if(argc < 2)
	{
		printf("ERROR:incorrect format of the command line arguments\n");
		printf("Info:./a.out --help for help menu\n");

	}
	else
	{
		//To check which operation needs to be performed based on the option passed in the command line.
		OperationType ret = check_operation(argv);
		if(ret == p_view)
		{
			printf("----------------------SELECTED VIEW DETAILS-----------------------");
			printf("\n");
			printf("\n");
			printf("------------------------------------------------------------------\n");
			printf("\t\tMP3 TAG READER AND EDITOR FOR ID3v2\n");
			printf("------------------------------------------------------------------\n");
			Status ret1 = read_and_validate_mp3_file(argv,&mp3tagInfo);//to validate all the arguments passdde in the command line
			if(ret1 == p_success)
			{
				Status ret2 = view_tag (argv,&mp3tagInfo);
				if(ret2 == p_success)
				{
					//if viewing process is successully completed print the confirmation message
					printf("Info:Completion of view details\n");
					printf("---------------------------------------------\n");
				}

			}
		}
		else if(ret == p_edit)
		{
			printf("-------------SELECTED EDIT DETAILS--------------------");
			printf("\n");
			printf("\n");
			printf("-------------------------------------------------------\n");
			printf ("MP3 TAG READER AND EDITOR FOR ID3v2\n");
            printf ("------------------------------------------------------\n");

            Status ret1 = read_and_validate_mp3_file_args (argv, &mp3tagData);	//To validate all the arguments passed in Command Line.
            if (ret1 == p_success)			//If validation is successful, proceed with the Editing process.
            {
                Status ret2 = edit_tag (argv, &mp3tagData);						//To execute the Editing process of the MP3 Tag.
                if (ret2 == p_success)		//If the Editing process is successfully executed, print a confirmation message.
                {
                    printf ("INFO: Completion of edit details\n");
                    printf ("---------------------------------------------\n");
                    //Call the view_tag function to display the Updated content.
                }
            }
		}
		else if(ret == p_help)
		{
			printf("INFO:Help menu for tag reader and editor\n");
			printf ("INFO: For Viewing the Tags -> ./a.out -v <file_name.mp3>\n");
            printf ("INFO: For Editing the Tags -> ./a.out -e <modifier> \"New_Value\" <file_name.mp3>\n");
            printf ("INFO: Modifier Functions:\n");
            printf ("-t\tModify Title Tag\n-A\tModify Artist Tag\n-a\tModify Album Tag\n-y\tModify Year Tag\n-G\tModify Content Type Tag\n-c\tModify Comments Tag\n");

		}
		else if(ret == p_unsupported)			//if the return value from the function is other than view/edit/help ,print an error message
		{
			printf("ERROR:Unsupported operation\n");
			printf("INFO:Use ./a.out --help for help menu\n");
		}
		return 0;
	}
}
