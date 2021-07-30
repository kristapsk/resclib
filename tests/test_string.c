#include <string.h>
#include "seatest.h"

static const char abcde[] = "abcde";
static const char abcdx[] = "abcdx";

static void test_strcat (void)
{
    char s[] = "xx\0xxxxxx";

    assert_true(sizeof(s) >= sizeof(abcde));
    assert_true(sizeof(s) >= 8);
    assert_true(sizeof(s) >= sizeof(abcdx));

    assert_true(strcat(s, abcde) == s);
    assert_true(s[2] == 'a');
    assert_true(s[6] == 'e');
    assert_true(s[7] == '\0');
    assert_true(s[8] == 'x');
    s[0] = '\0';
    assert_true(strcat(s, abcdx) == s);
    assert_true(s[4] == 'x');
    assert_true(s[5] == '\0');
    assert_true(strcat(s, "\0") == s);
    assert_true(s[5] == '\0');
    assert_true(s[6] == 'e');
}

static void test_strchr (void)
{
    char abccd[] = "abccd";

    assert_true(sizeof(abccd) >= 5);

    assert_true(strchr(abccd, 'x') == NULL);
    assert_true(strchr(abccd, 'a') == &abccd[0]);
    assert_true(strchr(abccd, 'd') == &abccd[4]);
    assert_true(strchr(abccd, '\0') == &abccd[5]);
    assert_true(strchr(abccd, 'c') == &abccd[2]);
}

static void test_strcmp (void)
{
    char cmpabcde[] = "abcde";
    char cmpabcd_[] = "abcd\xfc";
    char empty[] = "";

    assert_int_equal(sizeof(abcde), sizeof(cmpabcde));

    assert_int_equal(0, strcmp("", ""));
    assert_int_equal(0, strcmp("one", "one"));
    assert_int_equal(0, strcmp(abcde, cmpabcde));
    assert_true(strcmp(abcde, abcdx) < 0);
    assert_true(strcmp(abcdx, abcde) > 0);
    assert_true(strcmp(empty, abcde) < 0);
    assert_true(strcmp(abcde, empty) > 0);
    assert_true(strcmp(abcde, cmpabcd_) < 0);
}

static void test_strcpy (void)
{
    char s[] = "xxxxx";

    assert_true(sizeof(abcde) >= sizeof(s));
    assert_true(sizeof(s) >= 5);

    assert_true(strcpy(s, "") == s);
    assert_true(s[0] == '\0');
    assert_true(s[1] == 'x');
    assert_true(strcpy(s, abcde ) == s);
    assert_true(s[0] == 'a');
    assert_true(s[4] == 'e');
    assert_true(s[5] == '\0');
}

static void test_strcspn (void)
{
    assert_int_equal(6, sizeof(abcde));
    assert_true(sizeof(abcdx) > 4);

    assert_int_equal(5, strcspn(abcde, "x"));
    assert_int_equal(5, strcspn(abcde, "xyz"));
    assert_int_equal(5, strcspn(abcde, "zyx"));
    assert_int_equal(4, strcspn(abcdx, "x"));
    assert_int_equal(4, strcspn(abcdx, "xyz"));
    assert_int_equal(4, strcspn(abcdx, "zyx"));
    assert_int_equal(0, strcspn(abcde, "a"));
    assert_int_equal(0, strcspn(abcde, "abc"));
    assert_int_equal(0, strcspn(abcde, "cba"));
}

static void test_strlen (void)
{
    assert_int_equal(5, strlen(abcde));
    assert_int_equal(0, strlen(""));
}

static void test_strncat (void)
{
    char s[] = "xx\0xxxxxx";

    assert_int_equal(6, sizeof(abcdx));
    assert_true(sizeof(s) >= 8);
    assert_true(sizeof(abcde) >= 3);

    assert_true(strncat(s, abcde, 10) == s);
    assert_true(s[2] == 'a');
    assert_true(s[6] == 'e');
    assert_true(s[7] == '\0');
    assert_true(s[8] == 'x');
    s[0] = '\0';
    assert_true(strncat(s, abcdx, 10) == s);
    assert_true(s[4] == 'x');
    assert_true(s[5] == '\0');
    assert_true(strncat(s, "\0", 10) == s);
    assert_true(s[5] == '\0');
    assert_true(s[6] == 'e');
    assert_true(strncat(s, abcde, 0) == s);
    assert_true(s[5] == '\0');
    assert_true(s[6] == 'e');
    assert_true(strncat(s, abcde, 3) == s);
    assert_true(s[5] == 'a');
    assert_true(s[7] == 'c');
    assert_true(s[8] == '\0');
}

static void test_strncmp (void)
{
    char cmpabcde[] = "abcde\0f";
    char cmpabcd_[] = "abcde\xfc";
    char empty[] = "";
    char x[] = "x";

    assert_true(sizeof(abcde) < sizeof(cmpabcde));

    assert_int_equal(0, strncmp(abcde, cmpabcde, 5));
    assert_int_equal(0, strncmp(abcde, cmpabcde, 10));
    assert_true(strncmp(abcde, abcdx, 5) < 0);
    assert_true(strncmp(abcdx, abcde, 5) > 0);
    assert_true(strncmp(empty, abcde, 5) < 0);
    assert_true(strncmp(abcde, empty, 5) > 0);
    assert_int_equal(0, strncmp(abcde, abcdx, 4));
    assert_int_equal(0, strncmp(abcde, x, 0));
    assert_true(strncmp(abcde, x, 1) < 0);
    assert_true(strncmp(abcde, cmpabcd_, 10) < 0);
}

static void test_strncpy (void)
{
    char s[] = "xxxxxxx";

    assert_true(sizeof(s) >= 6);
    assert_true(sizeof(abcde) < 7);

    assert_true(strncpy(s, "", 1) == s);
    assert_true(s[0] == '\0');
    assert_true(s[1] == 'x');
    assert_true(strncpy(s, abcde, 6) == s);
    assert_true(s[0] == 'a');
    assert_true(s[4] == 'e');
    assert_true(s[5] == '\0');
    assert_true(s[6] == 'x');
    assert_true(strncpy(s, abcde, 7) == s);
    assert_true(s[6] == '\0');
    assert_true(strncpy(s, "xxxx", 3) == s);
    assert_true(s[0] == 'x');
    assert_true(s[2] == 'x');
    assert_true(s[3] == 'd');
}

static void test_strpbrk (void)
{
    assert_true(sizeof(abcdx) >= 4);

    assert_true(strpbrk(abcde, "x") == NULL);
    assert_true(strpbrk(abcde, "xyz") == NULL);
    assert_true(strpbrk(abcdx, "x") == &abcdx[4]);
    assert_true(strpbrk(abcdx, "xyz") == &abcdx[4]);
    assert_true(strpbrk(abcdx, "zyx" ) == &abcdx[4]);
    assert_true(strpbrk(abcde, "a") == &abcde[0]);
    assert_true(strpbrk(abcde, "abc") == &abcde[0]);
    assert_true(strpbrk(abcde, "cba") == &abcde[0]);
}

static void test_strrchr (void)
{
    char abccd[] = "abccd";

    assert_true(sizeof(abcde) >= 5);
    assert_true(sizeof(abccd) >= 3);

    assert_true(strrchr(abcde, '\0') == &abcde[5]);
    assert_true(strrchr(abcde, 'e') == &abcde[4]);
    assert_true(strrchr(abcde, 'a') == &abcde[0]);
    assert_true(strrchr(abccd, 'c') == &abccd[3]);
}

static void test_strspn (void)
{
    assert_int_equal(3, strspn(abcde, "abc"));
    assert_int_equal(0, strspn(abcde, "b"));
    assert_int_equal(5, strspn(abcde, abcde));
}

static void test_strstr (void)
{
    char s[] = "abcabcabcdabcde";

    assert_true(sizeof(s) >= 10);

    assert_true(strstr(s, "x") == NULL);
    assert_true(strstr(s, "xyz") == NULL);
    assert_true(strstr(s, "a") == &s[0]);
    assert_true(strstr(s, "abc") == &s[0]);
    assert_true(strstr(s, "abcd") == &s[6]);
    assert_true(strstr(s, "abcde") == &s[10]);
}

static void test_strtok (void)
{
    // Not implemented yet
/*
    char s[] = "_a_bc__d_";

    assert_true(strtok(s, "_") == &s[1]);
    assert_true(s[1] == 'a');
    assert_true(s[2] == '\0');
    assert_true(strtok(NULL, "_") == &s[3]);
    assert_true(s[3] == 'b');
    assert_true(s[4] == 'c');
    assert_true(s[5] == '\0');
    assert_true(strtok(NULL, "_") == &s[7]);
    assert_true(s[6] == '_');
    assert_true(s[7] == 'd');
    assert_true(s[8] == '\0');
    assert_true(strtok(NULL, "_") == NULL);
    strcpy(s, "ab_cd");
    assert_true(strtok(s, "_") == &s[0]);
    assert_true(s[0] == 'a');
    assert_true(s[1] == 'b');
    assert_true(s[2] == '\0');
    assert_true(strtok(NULL, "_") == &s[3]);
    assert_true(s[3] == 'c');
    assert_true(s[4] == 'd');
    assert_true(s[5] == '\0');
    assert_true(strtok(NULL, "_") == NULL);
*/    
}

void test_string (void)
{
    test_fixture_start();
    run_test(test_strcat);
    run_test(test_strchr);
    run_test(test_strcmp);
    run_test(test_strcpy);
    run_test(test_strcspn);
    run_test(test_strlen);
    run_test(test_strncat);
    run_test(test_strncmp);
    run_test(test_strncpy);
    run_test(test_strpbrk);
    run_test(test_strrchr);
    run_test(test_strspn);
    run_test(test_strstr);
    run_test(test_strtok);
    test_fixture_end();
}
