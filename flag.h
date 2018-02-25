
/* Maxium number of flags. */
#define FLAG_MAX 128

/* Maxium number of args. */
#define FLAG_MAX_ARGS 128

/* Size of error message. */
#define ERR_MSG_SIZE 2048

/*
 * FLAG_TYPE are an enum of the support types of flags.
 */
enum FLAG_TYPE {
        FLAG_TYPE_int,
        FLAG_TYPE_bool,
        FLAG_TYPE_str,
};

/*
 * flag is a structure that represents command line flag.
 * It holds the name of the flag, help description, and its value.
 */
struct flag {
        const char *name;
        const char *help;
        enum FLAG_TYPE type;
        union {
                int *i;
                bool *b;
                const char **s;
        } value;
};
