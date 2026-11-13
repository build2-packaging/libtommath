#include <string.h>

#include <tommath.h>

#undef NDEBUG
#include <assert.h>

int main ()
{
  mp_int a, b, c;
  char s[128];
  mp_bool p;

  assert (mp_init_multi (&a, &b, &c, NULL) == MP_OKAY);

  /* Multiply two numbers that don't fit into any built-in integer type and
   * convert the result back to its decimal representation.
   */
  {
    assert (mp_read_radix (&a, "123456789012345678901234567890", 10) ==
            MP_OKAY);
    assert (mp_read_radix (&b, "987654321098765432109876543210", 10) ==
            MP_OKAY);

    assert (mp_mul (&a, &b, &c) == MP_OKAY);

    assert (mp_to_radix (&c, s, sizeof (s), NULL, 10) == MP_OKAY);
    assert (strcmp (s,
                    "1219326311370217952261850327336229233322374638011112"
                    "63526900") == 0);
  }

  /* Test the Mersenne number 2^127 - 1 (prime) and its neighbor 2^127 + 1
   * (divisible by 3) for primality.
   */
  {
    int t = mp_prime_rabin_miller_trials (127);

    assert (mp_2expt (&a, 127) == MP_OKAY);
    assert (mp_sub_d (&a, 1, &b) == MP_OKAY);
    assert (mp_add_d (&a, 1, &c) == MP_OKAY);

    assert (mp_to_radix (&b, s, sizeof (s), NULL, 16) == MP_OKAY);
    assert (strcmp (s, "7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF") == 0);

    assert (mp_prime_is_prime (&b, t, &p) == MP_OKAY && p == MP_YES);
    assert (mp_prime_is_prime (&c, t, &p) == MP_OKAY && p == MP_NO);
  }

  /* Error reporting.
   */
  assert (strcmp (mp_error_to_string (MP_MEM), "Out of heap") == 0);

  mp_clear_multi (&a, &b, &c, NULL);

  return 0;
}
