
#define FLAG_MAX 128

#define FLAG_MAX_ARGS 128

/*
 * Flag types supported.
 */
typedef enum {
        FLAG_TYPE_INT,
        FLAG_TYPE_BOOL,
        FLAG_TYPE_STRING,
} FlagType;

/*
 * Flag represents as single user-defined
 * flag with a name, help description,
 * and pointer to the value.
 */
typedef struct Flag {
        const char *name;
        const char *help;
        FlagType type;
        union {
                bool *b;
                int *i;
                const char **s;
        } value;
} Flag;
