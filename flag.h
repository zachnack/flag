
/*
 * FlagType are an enum of the support types of flags.
 */
typedef enum {
        FLAG_TYPE_INT,
        FLAG_TYPE_BOOL,
        FLAG_TYPE_STR,
} FlagType;

/*
 * flag is a structure that represents command line flag.
 * It holds the name of the flag, help description, and its value.
 */
struct flag {
        const char *name;
        const char *help;
        FlagType type;
        union {
                bool *b;
                int *i;
                const char **s;
        } value;
};
